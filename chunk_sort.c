#include "push_swap.h"

void	chunk_sort(t_node **a, t_statistics *stats)
{
	t_node	*b;

	b = NULL;
	push_chunk_to_b(a, &b, stats);
	restore_from_b(a, &b, stats);
}
