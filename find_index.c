#include "push_swap.h"

int	find_index(t_node *stack, t_node *node)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack == node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
