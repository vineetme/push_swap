#include "push_swap.h"

int *stack_to_array(t_node *stack)
{
	t_node	*current;
	int		*array;
	int		i;

	array = malloc(stack_size(stack) * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}
