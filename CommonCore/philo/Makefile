# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 11:03:22 by dcsicsak          #+#    #+#              #
#    Updated: 2024/09/14 19:36:22 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
INCLUDES_DIR = includes

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/philo.c $(SRCS_DIR)/init.c \
		$(SRCS_DIR)/monitor.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/utils2.c \
		$(SRCS_DIR)/libft.c

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
