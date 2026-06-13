#include "push_swap.h"

static t_node	*find_biggest_node(t_node *stack)
{
	t_node	*biggest;

	if (stack == NULL)
		return (NULL);
	biggest = stack;
	while (stack != NULL)
	{
		if (stack->index > biggest->index)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void	restore_from_b(t_node **a, t_node **b, t_statistics *stats)
{
	t_node	*biggest;

	while (*b)
	{
		biggest = find_biggest_node(*b);
		move_node_to_top(b, biggest, stats);
		pa(b, a, stats);
	}
}
