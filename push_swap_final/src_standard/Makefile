NAME        = ../push_swap
BONUS_NAME  = ../checker

FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
CFLAGS     += -I. -I.. -I../bonus -I../bonus/src -I../bonus/gnl

SRCS        = adaptive.c assign_rank.c benchmark.c disorder.c main.c main_utils.c \
			 ../lst_utils/utils1.c ../lst_utils/utils2.c ../lst_utils/utils3.c ../lst_utils/utils_algo.c \
			 ../operations/push.c ../operations/rotation.c ../operations/rotation_2.c ../operations/switch.c \
			 ../medium/medium.c ../medium/medium_utils.c \
			 ../simple/simple.c \
			 ../complex/complex.c \
			 ../error_handlings/argument_pars.c ../error_handlings/handler_utils_1.c \
			 ../error_handlings/handler_utils_2.c ../error_handlings/handler_utils_3.c

OBJS        = $(SRCS:.c=.o)

BONUS_SRCS  = ../bonus/src/main.c ../bonus/src/instructions_utils.c \
			 ../bonus/instructions/push.c ../bonus/instructions/rotate.c \
			 ../bonus/instructions/rotate2.c ../bonus/instructions/swap.c \
			 ../bonus/gnl/get_next_line.c ../bonus/gnl/get_next_line_utils.c \
			 ../lst_utils/utils1.c \
			 ../error_handlings/argument_pars.c ../error_handlings/handler_utils_1.c \
			 ../error_handlings/handler_utils_2.c
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(FT_PRINTF_LIB) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus