#include "push_swap.h"

void	rrb(t_node **b)
{
	t_node	*current;
	t_node	*last;
	t_node	*penultimate;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	current = *b;
	last = last_node(*b);
	while (current->next->next != NULL)
		current = current->next;
	penultimate = current;
	penultimate->next = NULL;
	last->next = *b;
	*b = last;
}
