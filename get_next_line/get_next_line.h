/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:18:05 by mgo               #+#    #+#             */
/*   Updated: 2021/07/25 11:49:38 by refigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_gnl
{
	int		fd;
	char	*content;
	void	*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strjoin_with_free(char *s1, char *s2);
char			*ft_strndup(const char *str, ssize_t len);
char			*ft_strchr(const char *s, int c);
size_t			strlen(const char *s);

#endif
