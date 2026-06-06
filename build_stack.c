#include "push_swap.h"

t_node	*build_stack(int argc, char **argv)
{
	int		i;
	t_node	*stack;
	t_node	*new;

	i = 1;
	stack = new_node(ft_atol(argv[i]));
	i++;
	while (i < argc)
	{
		new = new_node(ft_atol(argv[i]));
		add_back(&stack, new);
		i++;
	}
	return (stack);
}
