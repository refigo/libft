/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_content_format_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:57:56 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 16:57:57 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	input_sign_content_with_precision(char *sign_str, \
	char **const temp_content_str, \
	char *const temp_nbr_str, t_format_info *info)
{
	*temp_content_str = strjoin_free_else(ft_strdup(sign_str), \
	malloc_chrstr('0', (size_t)info->precision - ft_strlen(temp_nbr_str)));
	write_to_malloc_str(temp_content_str, \
	temp_nbr_str, ft_strlen(temp_nbr_str));
}

static void	input_content_with_precision(char **const temp_content_str, \
	char *const temp_nbr_str, int nbr, t_format_info *info)
{
	if (nbr >= 0)
	{
		if (info->flag_plus == 1)
			input_sign_content_with_precision("+", \
			temp_content_str, temp_nbr_str, info);
		else if (info->flag_space == 1)
			input_sign_content_with_precision(" ", \
			temp_content_str, temp_nbr_str, info);
		else
		{
			*temp_content_str = strjoin_free_else(\
			malloc_chrstr('0', \
			(size_t)info->precision - ft_strlen(temp_nbr_str)), \
			temp_nbr_str);
			return ;
		}
	}
	else
		input_sign_content_with_precision("-", \
		temp_content_str, temp_nbr_str + 1, info);
	free(temp_nbr_str);
}

static void	input_content_with_no_precision(char **const temp_content_str, \
	char *const temp_nbr_str, int nbr, t_format_info *info)
{
	if (nbr >= 0 && info->flag_plus == 1)
		*temp_content_str = strjoin_free_else(ft_strdup("+"), temp_nbr_str);
	else if (nbr >= 0 && info->flag_space == 1)
		*temp_content_str = strjoin_free_else(ft_strdup(" "), temp_nbr_str);
	else
		*temp_content_str = temp_nbr_str;
}

void	make_content_format_int(char **const temp_content_str, \
	char *const temp_nbr_str, int nbr, t_format_info *info)
{
	if (info->precision != -1)
	{
		info->flag_zero = 0;
		if (nbr == 0)
			temp_nbr_str[0] = '\0';
		if ((size_t)info->precision >= ft_strlen(temp_nbr_str))
			input_content_with_precision(temp_content_str, \
			temp_nbr_str, nbr, info);
		else
			input_content_with_no_precision(temp_content_str, \
			temp_nbr_str, nbr, info);
	}
	else
		input_content_with_no_precision(temp_content_str, \
		temp_nbr_str, nbr, info);
}
