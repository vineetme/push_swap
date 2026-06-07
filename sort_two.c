#include "push_swap.h"

void	sort_two(t_node **stash)
{
	if (is_sorted(*stash))
		return ;
	sa(stash);
}
