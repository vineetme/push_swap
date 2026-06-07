#include "push_swap.h"

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	first = *b;
	last = last_node(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
}
