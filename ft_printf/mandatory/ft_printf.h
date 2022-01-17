/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:58:50 by mgo               #+#    #+#             */
/*   Updated: 2021/09/25 00:32:56 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FORMAT_TYPE "cspdiuxX%"

typedef struct s_format_info
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	size_t	width;
	int		precision;
	char	type;
	char	*buf_str;
}				t_format_info;

// ft_printf.c
int		ft_printf(const char *str, ...);
int		print_format(const char *str, va_list ap);
int		process_format(const char *str, int *i, va_list ap);
int		init_format_info(t_format_info **info);

// get_info_specifier_format.c
int		get_info_specifier_format(char spec, t_format_info *info);

// put_format_by_type.c
int		put_format_by_type(t_format_info *info, va_list ap);

// parse_format_char.c
int		parse_format_char(char c, t_format_info *info);

// parse_format_string.c
int		parse_format_str(char *str, t_format_info *info);

// parse_format_int.c
int		parse_format_int(int nbr, t_format_info *info);

// make_content_format_int.c
void	make_content_format_int(char **const temp_content_str, \
	char *const temp_nbr_str, int nbr, t_format_info *info);

// parse_format_unsigned.c
int		parse_format_unsigned(unsigned long long nbr, t_format_info *info);
void	make_width_format_nbr(char **const temp_width_str, \
	char *const temp_content_str, t_format_info *info);

// parse_format_percent.c
int		parse_format_percent(t_format_info *info);

// ft_printf_utils_str.c
int		write_to_malloc_str(char **dest, char *src, size_t src_size);
char	*malloc_chrstr(char c, size_t len);
char	*strjoin_free_else(char *s1, char *s2);

// ft_printf_utils_free.c
int		free_str_return_int(char *str, int ret_num);
int		free_info_return_int(t_format_info *info, int ret_num);
int		free_relocate_and_return_int(char **str, void *relocate, int ret_num);
int		free_two_return_int(char *s1, char *s2, int ret_num);

#endif
