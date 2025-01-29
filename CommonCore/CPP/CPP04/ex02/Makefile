NAME = animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -g

SRCS = srcs/main.cpp srcs/Animal.cpp srcs/Dog.cpp srcs/Brain.cpp\
	srcs/Cat.cpp srcs/WrongAnimal.cpp srcs/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re run valgrind
