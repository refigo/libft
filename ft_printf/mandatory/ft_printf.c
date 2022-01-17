/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:58:38 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:32:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_format_info(t_format_info **info)
{
	*info = (t_format_info *)malloc(sizeof(t_format_info));
	if (!info)
		return (0);
	(*info)->flag_minus = 0;
	(*info)->flag_plus = 0;
	(*info)->flag_space = 0;
	(*info)->flag_zero = 0;
	(*info)->flag_hash = 0;
	(*info)->width = 0;
	(*info)->precision = -1;
	(*info)->type = 0;
	(*info)->buf_str = 0;
	return (1);
}

int	process_format(const char *str, int *i, va_list ap)
{
	t_format_info	*info;
	int				ret_len_buf;

	ret_len_buf = 0;
	if (!init_format_info(&info))
		return (-1);
	(*i)++;
	while (!ft_strchr(FORMAT_TYPE, str[*i]))
	{
		if (!get_info_specifier_format(str[*i], info))
			return (free_info_return_int(info, -1));
		(*i)++;
	}
	info->type = str[*i];
	if (info->type)
	{
		ret_len_buf = put_format_by_type(info, ap);
		if (ret_len_buf == -1)
			return (free_info_return_int(info, -1));
		(*i)++;
	}
	free(info);
	return (ret_len_buf);
}

int	print_format(const char *str, va_list ap)
{
	int	ret_len_print;
	int	i;
	int	checker_len_format;

	ret_len_print = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar_fd(str[i++], 1);
			ret_len_print++;
		}
		if (str[i] == '%')
		{
			checker_len_format = process_format(str, &i, ap);
			if (checker_len_format == -1)
				return (-1);
			ret_len_print += checker_len_format;
		}
	}
	return (ret_len_print);
}

int	ft_printf(const char *format, ...)
{
	int		ret_len_print;
	va_list	ap;

	va_start(ap, format);
	ret_len_print = print_format(format, ap);
	va_end(ap);
	return (ret_len_print);
}
