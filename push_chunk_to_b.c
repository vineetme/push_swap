#include "push_swap.h"

static int	calculate_chunk_size(t_node *stack)
{
	int	size;
	int	sqrt;

	sqrt = 1;
	size = stack_size(stack);
	while ((sqrt * sqrt) <= size)
		sqrt++;
	return (size / sqrt);
}

static t_node	*find_chunk_member(t_node *stack, int chunk_start,
	int chunk_end)
{
	while (stack)
	{
		if (stack->index >= chunk_start && stack->index <= chunk_end)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_chunk_to_b(t_node **a, t_node **b, t_statistics *stats)
{
	int		chunk_size;
	int		chunk_start;
	int		chunk_end;
	t_node	*chunk_member;

	chunk_size = calculate_chunk_size(*a);
	chunk_start = 0;
	chunk_end = chunk_size - 1;
	while (*a != NULL)
	{
		chunk_member = find_chunk_member(*a, chunk_start, chunk_end);
		while (chunk_member != NULL)
		{
			move_node_to_top(a, chunk_member, stats);
			pb(a, b, stats);
			chunk_member = find_chunk_member(*a, chunk_start, chunk_end);
		}
		chunk_start += chunk_size;
		chunk_end += chunk_size;
	}
}
