# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 12:20:30 by dcsicsak          #+#    #+#              #
#    Updated: 2024/06/22 16:37:45 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fPIE
LDFLAGS = -pie
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = -lmlx -lX11 -lXext -lXrandr -lXrender -lXfixes -lXinerama -lXcursor \
-lGL -lGLU -lm

SRCS = srcs/main.c srcs/events.c srcs/render.c srcs/utils.c srcs/julia.c \
srcs/mandelbrot.c srcs/color.c srcs/parse.c srcs/ship.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./includes -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re


