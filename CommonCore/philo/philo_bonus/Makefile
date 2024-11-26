# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 11:03:22 by dcsicsak          #+#    #+#              #
#    Updated: 2024/11/26 06:47:09 by csicsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs
INCLUDES_DIR = includes

SRCS = $(SRCS_DIR)/philo_bonus.c \
		$(SRCS_DIR)/libft_bonus.c \
		$(SRCS_DIR)/libft2_bonus.c \
		$(SRCS_DIR)/sems_bonus.c \
		$(SRCS_DIR)/utils_bonus.c \
		$(SRCS_DIR)/utils2_bonus.c \
		$(SRCS_DIR)/monitoring_bonus.c \
		$(SRCS_DIR)/init_bonus.c \
		$(SRCS_DIR)/simulation_bonus.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re
