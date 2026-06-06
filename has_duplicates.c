#include "push_swap.h"

int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while ((j < argc) && ft_atol(argv[i]) != ft_atol(argv[j]))
			j++;
		if (j != argc)
			return (1);
		i++;
	}
	return (0);
}
