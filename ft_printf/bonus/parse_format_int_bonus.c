/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_int_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:59:26 by mgo               #+#    #+#             */
/*   Updated: 2021/09/23 12:59:27 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	make_bufstr_on_flag_minus(char *tmp_content_str, \
	char *tmp_width_str, int nbr, t_format_info *info)
{
	if (info->flag_minus == 1)
		info->buf_str = strjoin_free_else(tmp_content_str, tmp_width_str);
	else
	{
		if (nbr < 0 && info->flag_zero == 1)
		{
			info->buf_str = ft_strdup("-");
			if (!write_to_malloc_str(&(info->buf_str), \
			tmp_width_str, ft_strlen(tmp_width_str)))
				return (free_two_return_int(tmp_width_str, tmp_content_str, 0));
			if (!write_to_malloc_str(&(info->buf_str), \
			tmp_content_str + 1, ft_strlen(tmp_content_str + 1)))
				return (free_two_return_int(tmp_width_str, tmp_content_str, 0));
			free(tmp_width_str);
			free(tmp_content_str);
		}
		else
			info->buf_str = strjoin_free_else(tmp_width_str, tmp_content_str);
	}
	return (1);
}

int	parse_format_int(int nbr, t_format_info *info)
{
	char	*temp_nbr_str;
	char	*temp_content_str;
	char	*temp_width_str;

	temp_nbr_str = ft_itoa(nbr);
	if (!temp_nbr_str)
		return (0);
	make_content_format_int(&temp_content_str, temp_nbr_str, nbr, info);
	if (!temp_content_str)
		return (0);
	make_width_format_nbr(&temp_width_str, temp_content_str, info);
	if (!temp_width_str)
		free_str_return_int(temp_content_str, 0);
	make_bufstr_on_flag_minus(temp_content_str, temp_width_str, nbr, info);
	if (!(info->buf_str))
		return (0);
	return (1);
}
