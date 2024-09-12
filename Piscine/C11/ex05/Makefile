# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 09:37:51 by dcsicsak          #+#    #+#              #
#    Updated: 2024/03/07 09:37:59 by dcsicsak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS =  calc.c do_op.c ft_atoi.c ft_putnbr.c ft_strcmp.c

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
