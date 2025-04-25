NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD
VALFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
SRCS = srcs/main.cpp srcs/PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

run: fclean all
	./$(NAME)

result: CFLAGS += -DRESULT=1
result: fclean $(NAME)
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

.PHONY: all clean fclean re run valgrind result
