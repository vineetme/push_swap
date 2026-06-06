#include "push_swap.h"

void	add_back(t_node **stack, t_node *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last_node(*stack)->next = new;
}
