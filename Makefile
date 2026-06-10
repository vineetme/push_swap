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
		add_back.c \
		build_stack.c \
		debug_printstack.c \
		sa.c \
		sb.c \
		ss.c \
		pb.c \
		pa.c \
		ra.c \
		rb.c \
		rr.c \
		rra.c \
		rrb.c \
		rrr.c \
		is_sorted.c \
		sort_three.c \
		sort_two.c \
		find_smallest.c \
		find_index.c \
		stack_size.c \
		move_smallest_to_top.c \
		sort_four.c \
		sort_five.c \
		simple_sort.c \
		stack_to_array.c \
		merge_sort.c \
		merge.c \
		split_array.c \
		binary_search.c \
		assign_indexes.c

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


