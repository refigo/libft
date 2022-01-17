/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_specifier_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:59:08 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:33:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_width_format(size_t digit_width, t_format_info *info)
{
	info->width *= 10;
	info->width += digit_width;
}

static int	set_precision_format(int digit_prec, t_format_info *info)
{
	info->precision *= 10;
	info->precision += digit_prec;
	if (info->precision < 0)
		return (0);
	return (1);
}

static void	set_flag_considering_ignoring(\
	int *flag_to_set, int *flag_to_consider)
{
	if (*flag_to_consider == 1)
		*flag_to_set = 0;
	else
		*flag_to_set = 1;
}

static int	get_flags_format(char spec, t_format_info *info)
{
	if (ft_strchr("-+ 0#", spec) && \
	(info->width == 0) && (info->precision == -1))
	{
		if (spec == '-')
			info->flag_minus = 1;
		else if (spec == '+')
			info->flag_plus = 1;
		else if (spec == ' ')
			set_flag_considering_ignoring(\
			&(info->flag_space), &(info->flag_plus));
		else if (spec == '0')
			set_flag_considering_ignoring(\
			&(info->flag_zero), &(info->flag_minus));
		else if (spec == '#')
			info->flag_hash = 1;
		return (1);
	}
	else
		return (0);
}

int	get_info_specifier_format(char spec, t_format_info *info)
{
	if (get_flags_format(spec, info))
		return (1);
	else if (ft_isdigit(spec) && (info->precision == -1))
		set_width_format(spec - '0', info);
	else if (spec == '.' && (info->precision == -1))
		info->precision = 0;
	else if ((info->precision > -1) && ft_isdigit(spec))
	{
		if (!set_precision_format(spec - '0', info))
			return (0);
	}
	else
		return (0);
	return (1);
}
