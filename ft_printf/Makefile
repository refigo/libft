# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 13:04:40 by mgo               #+#    #+#              #
#    Updated: 2021/09/23 13:04:41 by mgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	./libft

DIR			=	mandatory
SRC_LIST	=	ft_printf.c \
				get_info_specifier_format.c \
				put_format_by_type.c \
				parse_format_char.c \
				parse_format_string.c \
				parse_format_int.c \
				make_content_format_int.c \
				parse_format_unsigned.c \
				parse_format_percent.c \
				ft_printf_utils_str.c \
				ft_printf_utils_free.c
SRCS		=	$(addprefix $(DIR)/, $(SRC_LIST))
OBJS		=	$(SRCS:.c=.o)

B_DIR		=	bonus
B_SRC_LIST	=	ft_printf_bonus.c \
				get_info_specifier_format_bonus.c \
				put_format_by_type_bonus.c \
				parse_format_char_bonus.c \
				parse_format_string_bonus.c \
				parse_format_int_bonus.c \
				make_content_format_int_bonus.c \
				parse_format_unsigned_bonus.c \
				parse_format_percent_bonus.c \
				ft_printf_utils_str_bonus.c \
				ft_printf_utils_free_bonus.c
B_SRCS		=	$(addprefix $(B_DIR)/, $(B_SRC_LIST))
B_OBJS		=	$(B_SRCS:.c=.o)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(OBJS)
	@make -C $(LIBFT) bonus
	@mv $(LIBFT)/libft.a ./$(NAME)
	ar -crs $(NAME) $^

bonus	:	$(B_OBJS)
	@make -C $(LIBFT) bonus
	@mv $(LIBFT)/libft.a ./$(NAME)
	ar -crs $(NAME) $^

clean	:
	@make clean -C $(LIBFT)
	@rm -f $(OBJS) $(B_OBJS)

fclean	:
	@make fclean -C $(LIBFT)
	@rm -f $(OBJS) $(B_OBJS) $(NAME)

re		:	fclean all

.PHONY	:	all bonus clean fclean re
