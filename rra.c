#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*penultimate;
	t_node	*current;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	current = *a;
	last = last_node(*a);
	while (current->next->next != NULL)
		current = current->next;
	penultimate = current;
	penultimate->next = NULL;
	last->next = *a;
	*a = last;
}
