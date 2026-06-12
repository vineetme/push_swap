#include "push_swap.h"

float	compute_disorder(t_node *stack)
{
	t_node	*first;
	t_node	*second;
	int		mistakes;
	int		pairs;

	mistakes = 0;
	pairs = 0;
	if (!stack || !stack->next)
		return (0.0f);
	first = stack;
	while (first != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (first->value > second->value)
				mistakes += 1;
			second = second->next;
			pairs++;
		}
		first = first->next;
	}
	return (((float)mistakes / (float)pairs) * 100);
}
