#include "push_swap.h"

void	pa(t_node **b, t_node **a)
{
	t_node	*first;

	if (*b == NULL)
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
}
