# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 11:03:22 by dcsicsak          #+#    #+#              #
#    Updated: 2024/04/16 19:34:31 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf_per.c ft_printf_di.c ft_printf_c.c ft_printf_s.c handle_format.c \
	ft_printf_p.c ft_printf_u.c ft_printf_xl.c ft_printf_xc.c in_set.c ft_printf.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
