NAME = my_awesome_phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRCS = srcs/Main.cpp srcs/Contact.cpp srcs/PhoneBook.cpp srcs/Utils.cpp

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
