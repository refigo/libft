/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:56:54 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:34:37 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_content_format_str(char **const temp_str, \
	char *str, t_format_info *info)
{
	if (!str)
		*temp_str = ft_strdup("(null)");
	else if (info->precision == -1 || \
	((size_t)info->precision >= ft_strlen(str)))
		*temp_str = ft_strdup(str);
	else
		*temp_str = ft_substr(str, 0, info->precision);
	if (!(*temp_str))
		return (0);
	if (!str && info->precision != -1 && \
	((size_t)info->precision < ft_strlen("(null)")))
		(*temp_str)[info->precision] = '\0';
	return (1);
}

int	parse_format_str(char *str, t_format_info *info)
{
	char	*temp_str;
	char	*temp_width_str;

	if (!make_content_format_str(&temp_str, str, info))
		return (0);
	if (info->width <= ft_strlen(temp_str))
		temp_width_str = ft_strdup("");
	else if (info->flag_zero != 1)
		temp_width_str = malloc_chrstr(' ', info->width - ft_strlen(temp_str));
	else
		temp_width_str = malloc_chrstr('0', info->width - ft_strlen(temp_str));
	if (!temp_width_str)
		return (free_str_return_int(temp_str, 0));
	if (info->flag_minus == 1)
		info->buf_str = strjoin_free_else(temp_str, temp_width_str);
	else
		info->buf_str = strjoin_free_else(temp_width_str, temp_str);
	if (!(info->buf_str))
		return (0);
	return (1);
}
