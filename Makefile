NAME = minishell

PARS_DIR = ./parsing
EXE_DIR = ./execution
BUILTIN_DIR = ./builtins

SOURCES = \
main.c \
$(PARS_DIR)/parsing_utils.c \
$(PARS_DIR)/cmd_utils.c \
$(PARS_DIR)/parsing_files.c \
$(PARS_DIR)/parsing_files2.c \
$(PARS_DIR)/flag_utils.c \
$(PARS_DIR)/exit_utils.c \
$(PARS_DIR)/expansion.c \
$(PARS_DIR)/parsing.c \
$(PARS_DIR)/ft_supersplit.c \
$(PARS_DIR)/checksyntax.c \
$(EXE_DIR)/pipex.c \
$(EXE_DIR)/pipe_utils.c \
$(EXE_DIR)/built_in.c \
$(EXE_DIR)/exec_utils.c \
$(EXE_DIR)/file_utils.c \
$(EXE_DIR)/file_utils2.c \
$(EXE_DIR)/quotes.c \
$(BUILTIN_DIR)/echo.c \
$(BUILTIN_DIR)/cd.c \
$(BUILTIN_DIR)/export.c \
$(BUILTIN_DIR)/unset.c \
$(BUILTIN_DIR)/env.c \
$(BUILTIN_DIR)/pwd.c \
$(BUILTIN_DIR)/exit.c \
signals.c

OBJS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra  -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	make -C Libft/ all
	cc $(CFLAGS) $(SOURCES) Libft/libft.a -lreadline -o $(NAME) 

clean:
		rm -f $(OBJS)
		make -C Libft/ clean

fclean: clean
		rm -f $(NAME)
		make -C Libft/ fclean

re: fclean all

.PHONY: all clean fclean re