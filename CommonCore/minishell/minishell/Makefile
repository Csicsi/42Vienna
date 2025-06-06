NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	srcs/minishell.c \
		srcs/initialize.c \
		srcs/lexer/lexer.c \
		srcs/lexer/lexer_utils.c \
		srcs/lexer/expansion.c \
		srcs/lexer/var_len.c \
		srcs/lexer/quotes.c \
		srcs/lexer/tokens_postprocess.c \
		srcs/lexer/validate_syntax.c \
		srcs/execution/execute_list.c \
		srcs/execution/execute_child.c \
		srcs/execution/execute_single.c \
		srcs/execution/redirs.c \
		srcs/execution/execute_utils1.c \
		srcs/execution/execute_utils2.c \
		srcs/execution/heredoc.c \
		srcs/execution/heredoc_utils.c \
		srcs/execution/find_cmd_path.c \
		srcs/parser/parser.c \
		srcs/parser/token_handlers.c \
		srcs/parser/handle_io.c \
		srcs/parser/validate_grammar.c \
		srcs/builtins/echo.c \
		srcs/builtins/cd.c \
		srcs/builtins/cd_utils1.c \
		srcs/builtins/cd_utils2.c \
		srcs/builtins/ft_realpath.c \
		srcs/builtins/pwd.c \
		srcs/builtins/export.c \
		srcs/builtins/export_utils.c \
		srcs/builtins/unset.c \
		srcs/builtins/env.c \
		srcs/builtins/exit.c \
		srcs/utils/utils1.c \
		srcs/utils/utils2.c \
		srcs/utils/utils3.c \
		srcs/utils/utils4.c \
		srcs/utils/cleanup.c \
		srcs/utils/ft_fprintf.c \
		srcs/utils/ft_fprintf_utils.c \
		srcs/signals/signals.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./includes -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re
