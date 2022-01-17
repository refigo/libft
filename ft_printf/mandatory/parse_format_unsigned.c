/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:00:13 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:34:49 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_width_format_nbr(char **const temp_width_str, \
	char *const temp_content_str, t_format_info *info)
{
	if (info->width > ft_strlen(temp_content_str))
	{
		if (info->flag_zero == 1)
			*temp_width_str = malloc_chrstr('0', \
			info->width - ft_strlen(temp_content_str));
		else
			*temp_width_str = malloc_chrstr(' ', \
			info->width - ft_strlen(temp_content_str));
	}
	else
		*temp_width_str = ft_strdup("");
}

static int	put_unsigned_recursively(unsigned long long nbr, char *nbr_set, \
	unsigned long long base_size, char **str_unsigned)
{
	if (nbr > (base_size - 1))
	{
		if (!put_unsigned_recursively((nbr / (base_size)), nbr_set, \
		base_size, str_unsigned))
			return (0);
	}
	if (!write_to_malloc_str(str_unsigned, \
	&(nbr_set[nbr % (base_size)]), 1))
		return (0);
	return (1);
}

static int	make_unsigned_str(char **const temp_unsigned_str, \
	unsigned long long nbr, t_format_info *info)
{
	char	*nbr_set;

	if (info ->type == 'u')
		nbr_set = "0123456789";
	else if (info->type == 'x' || info->type == 'p')
		nbr_set = "0123456789abcdef";
	else if (info->type == 'X')
		nbr_set = "0123456789ABCDEF";
	if (info->type == 'p' || \
	(info->type == 'x' && info->flag_hash == 1 && nbr != 0))
		*temp_unsigned_str = ft_strdup("0x");
	else if (info->type == 'X' && info->flag_hash == 1 && nbr != 0)
		*temp_unsigned_str = ft_strdup("0X");
	else
		*temp_unsigned_str = ft_strdup("");
	if (!(*temp_unsigned_str))
		return (0);
	if (!put_unsigned_recursively(nbr, nbr_set, \
	ft_strlen(nbr_set), temp_unsigned_str))
		return (0);
	return (1);
}

static void	make_precision_format_unsigned(char **const temp_content_str, \
	char *const temp_unsigned_str, unsigned long long nbr, t_format_info *info)
{
	if (info->precision != -1)
	{
		info->flag_zero = 0;
		if (nbr == 0)
			temp_unsigned_str[0] = '\0';
		if ((size_t)info->precision > ft_strlen(temp_unsigned_str))
			*temp_content_str = strjoin_free_else(\
			malloc_chrstr('0', \
			(size_t)info->precision - ft_strlen(temp_unsigned_str)), \
			temp_unsigned_str);
		else
			*temp_content_str = temp_unsigned_str;
	}
	else
		*temp_content_str = temp_unsigned_str;
}

int	parse_format_unsigned(unsigned long long nbr, t_format_info *info)
{
	char	*temp_unsigned_str;
	char	*temp_content_str;
	char	*temp_width_str;

	if (info->type == 'p' && (info->flag_zero == 1 || info->precision != -1))
		return (0);
	if (!make_unsigned_str(&temp_unsigned_str, nbr, info))
		return (0);
	make_precision_format_unsigned(&temp_content_str, \
	temp_unsigned_str, nbr, info);
	if (!temp_content_str)
		return (0);
	make_width_format_nbr(&temp_width_str, temp_content_str, info);
	if (!temp_width_str)
		free_str_return_int(temp_content_str, 0);
	if (info->flag_minus == 1)
		info->buf_str = strjoin_free_else(temp_content_str, temp_width_str);
	else
		info->buf_str = strjoin_free_else(temp_width_str, temp_content_str);
	if (!(info->buf_str))
		return (0);
	return (1);
}
