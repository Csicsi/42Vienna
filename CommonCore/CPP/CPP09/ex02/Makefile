NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD
VALFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
SRCS = srcs/main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

run: all
	./$(NAME)

valgrind: all
	valgrind $(VALFLAGS) ./$(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: all clean fclean re run valgrind
