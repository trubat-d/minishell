SRCS = srcs/main/main.c \
		srcs/ast/ast.c srcs/ast/precedence.c srcs/ast/precedence_utils.c \
		srcs/builtins/cd.c srcs/builtins/echo.c srcs/builtins/env.c srcs/builtins/exit.c  srcs/builtins/export.c  srcs/builtins/pwd.c srcs/builtins/unset.c srcs/builtins/export_utils.c \
		srcs/exec/basic.c srcs/exec/chevron.c srcs/exec/chevron_utils.c srcs/exec/pipe_cmd_utils.c srcs/exec/tree.c srcs/exec/pipe.c srcs/exec/pipe_cmd.c srcs/exec/pipe_built_in.c srcs/exec/start_exec.c \
		srcs/parsing/classify.c srcs/parsing/classify_utils.c srcs/parsing/parse_ast.c srcs/parsing/parse_bracket.c srcs/parsing/parse_error.c srcs/parsing/parse_split.c srcs/parsing/parse_var.c srcs/parsing/parse_var_utils.c \
		srcs/utils/path.c srcs/utils/signal.c srcs/utils/utils.c  \
		srcs/free/free.c
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = libft
HEADER = includes
NAME = minishell
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
GCC = gcc -g
CC = gcc -g -lreadline

FLAGS += -I$(HOME)/.brew/opt/readline/include
READLINE += -L$(HOME)/.brew/opt/readline/lib

.c.o:
			${GCC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}	
				make -C ${LIBFT_DIR}
				cp ${LIBFT_DIR}/libft.a .
				${CC} ${OBJS} ${CFLAGS} ${FLAGS} ${READLINE} libft.a -o ${NAME}

all: $(NAME)

clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT_DIR}

fclean:		clean
			${RM} ${NAME}
			${RM} libft.a
			make fclean -C ${LIBFT_DIR}

re:			fclean all

.PHONY: all clean fclean re