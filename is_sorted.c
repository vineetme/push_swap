#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (stack == NULL)
		return (1);
	while(stack->next != NULL)
	{
		if(stack->value > (stack->next)->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
