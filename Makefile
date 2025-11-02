CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = push_swap.c\
	   push_swap_utils.c\
	   op_push.c\
	   op_rev_rotate.c\
	   op_rotate.c\
	   op_swap.c\
	   parse_args.c\
	   parse_flags.c\
	   sort_bubble.c\
	   sort_radix.c\
	   sort_chunk.c\
	   stack.c\
	   stack_utils.c


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF_DIR = ./ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)	
	$(MAKE) -C $(FTPRINTF_DIR)	
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FTPRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)	clean
	$(MAKE) -C $(FTPRINTF_DIR)	clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FTPRINTF)

# re: fclean all 
re:
	@$(MAKE) fclean
	@$(MAKE) all
	@$(MAKE) clean
	
.PHONY: all bonus clean fclean re
