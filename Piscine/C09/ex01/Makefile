NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
SRC_DIR = ./srcs
SRCS = $(SRC_DIR)/ft_putchar.c \
	   $(SRC_DIR)/ft_swap.c \
	   $(SRC_DIR)/ft_putstr.c \
	   $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
.DEFAULT_GOAL := all
