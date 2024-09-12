# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:41:02 by dcsicsak          #+#    #+#              #
#    Updated: 2024/07/05 14:29:20 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_SERVER = srcs/server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = srcs/client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS = srcs_bonus/server_bonus.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

SRCS_CLIENT_BONUS = srcs_bonus/client_bonus.c
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

INCLUDES = -I ./includes -I $(LIBFT_DIR)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER): $(LIBFT) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(LIBFT) $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(LIBFT) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
