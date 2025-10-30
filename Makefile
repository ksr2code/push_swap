CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = main.c\
	   check_arg.c\
	   push.c\
	   rotate.c\
	   sort.c\
	   stack.c\
	   stack_utils.c\
	   utils.c


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)	
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)	clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all
	
.PHONY: all bonus clean fclean re
