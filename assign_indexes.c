#include "push_swap.h"

void	assign_indexes(t_node *stack)
{
	int		*array;
	t_node	*current;
	int		size;

	size = stack_size(stack);
	current = stack;
	array = stack_to_array(stack);
	merge_sort(array, size);
	while (current != NULL)
	{
		current->index = binary_search(array, size, current->value);
		current = current->next;
	}
	free (array);
}
