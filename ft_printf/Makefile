CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
MANDATORY_SRCS = 
BONUS_SRCS = 
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	FINAL_OBJS = $(MANDATORY_OBJS) $(BONUS_OBJS)
else
	FINAL_OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)

bonus : 
	make WITH_BONUS=1 all

$(NAME) : $(FINAL_OBJS)
	ar rcs $@ $^

$(MANDATORY_OBJS) :
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)
$(BONUS_OBJS) :
	$(CC) $(CFLAGS) -c $(BONUS_SRCS)

clean :
	rm -rf $(MANDATORY_OBJS)
	rm -rf $(BONUS_OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all bonus clean fclean re