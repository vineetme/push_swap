#include "push_swap.h"

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}
