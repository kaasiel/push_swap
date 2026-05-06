NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_bigint.c \
		ft_putendl.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_puthex_maj.c \
		ft_puthex.c \
		ft_tester.c \
		ft_ptr.c \
		ft_putfloat.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re