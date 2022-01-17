/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:59:35 by mgo               #+#    #+#             */
/*   Updated: 2021/09/23 12:59:37 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_to_malloc_str(char **dest, char *src, size_t src_size)
{
	char	*result;
	size_t	dest_size;
	size_t	i;

	if (!(*dest) || !src)
		return (free_relocate_and_return_int(dest, 0, 0));
	dest_size = ft_strlen(*dest);
	result = (char *)malloc(dest_size + src_size + 1);
	if (!result)
		return (free_relocate_and_return_int(dest, 0, 0));
	ft_memset(result, 0, dest_size + src_size + 1);
	ft_memmove(result, *dest, dest_size);
	i = 0;
	while (i < src_size)
	{
		result[dest_size + i] = src[i];
		i++;
	}
	return (free_relocate_and_return_int(dest, result, 1));
}

char	*malloc_chrstr(char c, size_t len)
{
	char	*ret_chrstr;

	ret_chrstr = (char *)malloc(len + 1);
	if (!ret_chrstr)
		return (0);
	ret_chrstr[len] = '\0';
	while (len)
		ret_chrstr[--len] = c;
	return (ret_chrstr);
}

char	*strjoin_free_else(char *s1, char *s2)
{
	char	*ret_joined;

	ret_joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret_joined);
}
