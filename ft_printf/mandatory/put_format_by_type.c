/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format_by_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:47:59 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:34:58 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_format_char(t_format_info *info)
{
	if (info->width > 0)
	{
		write(1, info->buf_str, info->width);
		return (info->width);
	}
	else
	{
		write(1, info->buf_str, 1);
		return (1);
	}
}

int	put_format_by_type(t_format_info *info, va_list ap)
{
	int	ret_len_buf;

	if (info->type == 'c')
		parse_format_char(va_arg(ap, int), info);
	else if (info->type == 's')
		parse_format_str(va_arg(ap, char *), info);
	else if (info->type == 'p')
		parse_format_unsigned((unsigned long long)va_arg(ap, void *), info);
	else if (info->type == 'd' || info->type == 'i')
		parse_format_int(va_arg(ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		parse_format_unsigned(va_arg(ap, unsigned int), info);
	else if (info->type == '%')
		parse_format_percent(info);
	if (!(info->buf_str))
		return (-1);
	if (info->type != 'c')
	{
		ft_putstr_fd(info->buf_str, 1);
		ret_len_buf = ft_strlen(info->buf_str);
	}
	else
		ret_len_buf = put_format_char(info);
	free(info->buf_str);
	return (ret_len_buf);
}
