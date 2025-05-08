NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD
SRCS = srcs/main.cpp srcs/PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

result: CFLAGS += -DRESULT=1
result: fclean $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: all clean fclean re result
