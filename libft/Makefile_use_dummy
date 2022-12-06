CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libft.a
MANDATORY_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strmapi.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_strncmp.c
BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)
bonus : make_bonus

make_bonus : $(NAME) $(BONUS_OBJS)
	ar rcs $^
	touch $@

$(NAME) : $(MANDATORY_OBJS)
	ar rcs $@ $^
$(MANDATORY_OBJS) :
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)
$(BONUS_OBJS) : 
	$(CC) $(CFLAGS) -c $(BONUS_SRCS)

clean :
	rm -rf $(MANDATORY_OBJS)
	rm -rf $(BONUS_OBJS)
	rm -rf make_bonus
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all bonus clean fclean re