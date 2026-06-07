#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = last_node(*a);
	last->next = first;
}
