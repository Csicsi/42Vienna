NAME = zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = srcs/Zombie.cpp srcs/zombieHorde.cpp srcs/main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
