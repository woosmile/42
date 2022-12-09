CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c print_addr.c print_char.c print_hex.c print_nbr_u.c print_nbr.c print_str.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	ar rcs $@ $^

$(MANDATORY_OBJS) :
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)

clean :
	rm -rf $(MANDATORY_OBJS)
	make -C $(LIBFT) clean
fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean
re : fclean all

.PHONY : all clean fclean re