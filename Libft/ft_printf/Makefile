NAME = libftprintf.a
SOURCES = \
ft_printf.c \
ft_printhexa.c \
ft_printint.c \
ft_printptr.c \
ft_printunsigned.c

OBJS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all