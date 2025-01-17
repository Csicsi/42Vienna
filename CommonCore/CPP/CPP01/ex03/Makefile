NAME = fight
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = srcs/main.cpp srcs/HumanA.cpp srcs/HumanB.cpp srcs/Weapon.cpp

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
