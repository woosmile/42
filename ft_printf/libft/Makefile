CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libft.a
MANDATORY_SRCS = ft_strlen.c
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