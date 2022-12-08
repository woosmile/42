CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c print_addr.c print_char.c print_hex.c print_nbr_u.c print_nbr.c print_str.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS)
	ar rcs $@ $^

$(MANDATORY_OBJS) :
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)

clean :
	rm -rf $(MANDATORY_OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re