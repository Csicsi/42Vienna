NAME = forms
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
SRCS = srcs/main.cpp srcs/Bureaucrat.cpp \
	srcs/GradeTooHighExceptionBase.cpp \
	srcs/GradeTooLowExceptionBase.cpp srcs/AForm.cpp \
	srcs/ShrubberyCreationForm.cpp \
	srcs/RobotomyRequestForm.cpp srcs/PresidentialPardonForm.cpp \
	srcs/NotSignedExceptionBase.cpp

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
