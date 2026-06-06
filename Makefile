NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		ft_atol.c \
		is_valid_number.c \
		is_number_in_range.c \
		has_duplicates.c \
		error.c \
		new_node.c \
		last_node.c \

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


