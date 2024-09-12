# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.your42network>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 16:37:29 by icseri            #+#    #+#              #
#    Updated: 2024/03/06 20:04:25 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS =  main.c basic_functions.c backtracking.c	checks.c input_parsing.c size_functions.c malloc.c std_in.c std_in_support.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	cc ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS}
	cc ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}

fclean: 
	rm -f ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re
