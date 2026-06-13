#include "push_swap.h"

void	move_node_to_top(t_node **stack, t_node *target, t_statistics *stats)
{
	int	mid;
	int	position;
	
	mid = stack_size(*stack) / 2;
	position = find_index(*stack, target);
	if (position <= mid)
	{
		while (*stack != target)
			ra(stack, stats);
	}
	else
	{
		while (*stack != target)
			rra(stack, stats);
	}
}

