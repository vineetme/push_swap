#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*first;

	if (*a == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
}
