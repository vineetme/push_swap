#include "push_swap.h"

t_node	*find_smallest(t_node *stack)
{
	t_node	*smallest;
	t_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	smallest = stack;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}
