/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:55:44 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:33:50 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_width_format_char(char c, t_format_info *info)
{
	if (info->flag_minus == 1)
	{
		(info->buf_str)[0] = c;
		ft_memset(&((info->buf_str)[1]), ' ', info->width - 1);
	}
	else
	{
		ft_memset(&((info->buf_str)[0]), ' ', info->width - 1);
		(info->buf_str)[info->width - 1] = c;
	}
	(info->buf_str)[info->width] = '\0';
}

int	parse_format_char(char c, t_format_info *info)
{
	if (info->flag_zero != 0 || info->precision != -1)
		return (0);
	if (info->width > 0)
		info->buf_str = (char *)malloc(info->width + 1);
	else
		info->buf_str = (char *)malloc(sizeof(char) + 1);
	if (!(info->buf_str))
		return (0);
	if (info->width > 1)
		make_width_format_char(c, info);
	else
	{
		(info->buf_str)[0] = c;
		(info->buf_str)[1] = '\0';
	}
	return (1);
}
