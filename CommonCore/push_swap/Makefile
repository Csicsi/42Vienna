# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 11:03:22 by dcsicsak          #+#    #+#              #
#    Updated: 2024/07/03 11:21:30 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/push_swap.c srcs/stack.c srcs/s_ops.c srcs/p_ops.c srcs/r_ops.c \
srcs/rr_ops.c srcs/sort.c srcs/cost.c srcs/move.c srcs/parse.c srcs/utils.c \
srcs/rank.c srcs/calculate.c srcs/simple_sort.c srcs/simple_sort_utils.c
CHECKER_SRCS = srcs_bonus/checker.c srcs/stack.c srcs_bonus/s_bonus.c \
srcs_bonus/p_bonus.c srcs_bonus/r_bonus.c srcs_bonus/rr_bonus.c \
srcs/utils.c srcs/parse.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(CHECKER_SRCS:.c=.o)

INCLUDES = -I ./includes -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

bonus: $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus
