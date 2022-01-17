/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_percent_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:59:18 by mgo               #+#    #+#             */
/*   Updated: 2021/09/23 12:59:21 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_format_percent(t_format_info *info)
{
	char	*temp_width_str;

	if (info->width > 1)
	{
		if (info->flag_zero == 1)
			temp_width_str = malloc_chrstr('0', (size_t)info->width - 1);
		else
			temp_width_str = malloc_chrstr(' ', (size_t)info->width - 1);
	}
	else
		temp_width_str = ft_strdup("");
	if (!temp_width_str)
		return (0);
	if (info->flag_minus == 1)
		info->buf_str = ft_strjoin("%", temp_width_str);
	else
		info->buf_str = ft_strjoin(temp_width_str, "%");
	free(temp_width_str);
	if (!(info->buf_str))
		return (0);
	return (1);
}
