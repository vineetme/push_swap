#include "push_swap.h"

void	sort_five(t_node **a)
{
	t_node	*b;

	b = NULL;
	move_smallest_to_top(a);
	pb(a, &b);
	sort_four(a);
	pa(&b, a);
}
