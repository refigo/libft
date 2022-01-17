/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_free_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:11:07 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:11:09 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	free_str_return_int(char *str, int ret_num)
{
	free(str);
	return (ret_num);
}

int	free_info_return_int(t_format_info *info, int ret_num)
{
	free(info);
	return (ret_num);
}

int	free_relocate_and_return_int(char **str, void *relocate, int ret_num)
{
	free(*str);
	*str = relocate;
	return (ret_num);
}

int	free_two_return_int(char *s1, char *s2, int ret_num)
{
	free(s1);
	free(s2);
	return (ret_num);
}
