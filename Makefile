FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SOURCES = libft/ft_atoi.c libft/ft_split.c printf/ft_printf2.c\
		libft/ft_strdup.c libft/ft_strlen.c\
		printf/ft_printf.c push_swap.c push_swap_rotate.c push_swap_push.c \
		push_swap_reverse_rot.c push_swap_swap.c \
		push_swap_checkers.c\
		push_swap_cheapest_to_top.c\
		push_swap_algorithm.c\
		push_swap_push_back_a_utils.c push_swap_push_to_b_utils.c\
		push_swap_push_both_utils.c\

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	cc -g -o push_swap -Wall -Werror -Wextra $(SOURCES)

%.o:%.c ft_printf.h
	cc -c $(FLAGS) -o $@ $<  

clean:
	rm -f  $(OBJECT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

exec:
	cc -g -o push_swap -Wall -Werror -Wextra $(SOURCES)

.PHONY: all clean fclean re
