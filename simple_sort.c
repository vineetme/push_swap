#include "push_swap.h"

void	simple_sort(t_node **a)
{
	t_node	*b;

	b = NULL;
	while (stack_size(*a) > 5)
	{
		move_smallest_to_top(a);
		pb (a, &b);
	}
	sort_five(a);
	while (b != NULL)
		pa(&b, a);
}
