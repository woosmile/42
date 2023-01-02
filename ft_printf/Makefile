CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c print_addr.c print_char.c print_hex.c print_nbr_u.c print_nbr.c print_str.c
BONUS_SRCS = check_options_bonus.c addr_bonus.c char_bonus.c hex_input_bonus.c hex_main_bonus.c \
nbr_check_options_bonus.c nbr_input_bonus.c nbr_main_bonus.c str_bonus.c ft_printf_bonus.c total_length_bonus.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

ifdef WITH_BONUS
        FINAL_OBJS = $(BONUS_OBJS)
else
        FINAL_OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)
bonus :
	sleep 1
	make WITH_BONUS=1 all

$(NAME) : $(FINAL_OBJS)
	make -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	ar rcs $@ $^

$(MANDATORY_OBJS) :
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)

$(BONUS_OBJS) :
	$(CC) $(CFLAGS) -c $(BONUS_SRCS)

clean :
	make -C $(LIBFT) clean	
	rm -rf $(MANDATORY_OBJS)
	rm -rf $(BONUS_OBJS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re