NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = \
		ft_atol.c \
		is_valid_number.c \
		is_number_in_range.c \
		has_duplicates.c \
		validate_inputs.c \
		error.c \
		new_node.c \
		last_node.c \
		add_back.c \
		build_stack.c \
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
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strlen.c \
		init_statistics.c \
		free_stack.c \
		build_input_stack.c \
		ft_split.c \
		ft_substr.c \
		free_split.c \
		split_count.c \
		ft_strdup.c

PUSH_SWAP_SRCS = \
		main.c \
		debug_printstack.c \
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
		assign_indexes.c \
		parse_flags.c \
		compute_disorder.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putfloat.c \
		resolve_strategy.c \
		execute_strategy.c \
		print_benchmark.c \
		radix_sort.c \
		move_a_to_top.c \
		move_b_to_top.c \
		push_chunk_to_b.c \
		restore_from_b.c \
		chunk_sort.c

CHECKER_SRCS = \
		checker.c \
		checker_read.c \
		checker_execute.c \
		get_next_line.c \
		get_next_line_utils.c

PUSH_SWAP_OBJS = $(COMMON_SRCS:.c=.o) $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(COMMON_SRCS:.c=.o) $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(BONUS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
