/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:15:09 by mgo               #+#    #+#             */
/*   Updated: 2021/07/25 11:46:24 by refigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new_storage(int fd)
{
	t_gnl	*ret;

	ret = malloc(sizeof(t_gnl));
	if (!ret)
		return (NULL);
	ret->fd = fd;
	ret->content = 0;
	ret->next = 0;
	return (ret);
}

static t_gnl	*set_carrier(t_gnl **storage, int fd)
{
	t_gnl	*carrier;
	t_gnl	*tmp;

	if (!(*storage))
	{
		*storage = new_storage(fd);
		if (!(*storage))
			return (NULL);
	}
	carrier = *storage;
	while (carrier && (fd != carrier->fd))
	{
		tmp = carrier;
		carrier = carrier->next;
	}
	if (!carrier)
	{
		carrier = new_storage(fd);
		if (!(carrier))
			return (NULL);
		tmp->next = carrier;
	}
	return (carrier);
}

static int	del_storage(t_gnl **storage, int fd)
{
	t_gnl	*prev;
	t_gnl	*tmp;

	prev = 0;
	tmp = *storage;
	if (tmp == 0)
		return (-1);
	while ((tmp->next) && (tmp->fd != fd))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
		*storage = tmp->next;
	else if (prev)
		prev->next = tmp->next;
	if (fd == tmp->fd)
	{
		free(tmp->content);
		free(tmp);
	}
	return (-1);
}

static int	set_line(char **line, t_gnl **storage, t_gnl *carrier)
{
	char	*newl;
	char	*tmp_content;

	newl = ft_strchr(carrier->content, '\n');
	if (newl)
	{
		*line = ft_strndup(carrier->content, (newl - carrier->content));
		if (!(*line))
			return (-1);
		tmp_content = carrier->content;
		carrier->content = ft_strndup(newl + 1, strlen(newl + 1));
		if (!(carrier->content))
		{
			free(tmp_content);
			return (del_storage(storage, carrier->fd));
		}
		free(tmp_content);
		return (1);
	}
	else
	{
		*line = ft_strndup(carrier->content, strlen(carrier->content));
		if (!(*line))
			return (-1);
		del_storage(storage, carrier->fd);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*storage;
	t_gnl			*carrier;
	char			buf[BUFFER_SIZE + 1];
	ssize_t			read_size;

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	carrier = set_carrier(&storage, fd);
	if (!(carrier))
		return (del_storage(&storage, fd));
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size >= 0)
	{
		buf[read_size] = '\0';
		if (carrier->content)
			carrier->content = ft_strjoin_with_free(carrier->content, buf);
		else
			carrier->content = ft_strndup(buf, read_size);
		if (!(carrier->content))
			return (del_storage(&storage, fd));
		if (ft_strchr(carrier->content, '\n') || read_size == 0)
			break ;
	}
	if (read_size < 0)
		return (del_storage(&storage, fd));
	return (set_line(line, &storage, carrier));
}
