#include "push_swap.h"
#include <stdio.h>

void	debug_printstack(int argc, char **argv)
{
	t_node *ptr;

	ptr = build_stack(argc, argv);
	while (ptr != NULL)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}
