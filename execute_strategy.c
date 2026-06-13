#include "push_swap.h"

void	execute_strategy(t_node **stack, t_config *config)
{
	if (config->resolved_strategy == simple)
		simple_sort(stack, &config->stats);
	else if (config->resolved_strategy == medium)
		chunk_sort(stack, &config->stats);
	else if (config->resolved_strategy == complex)
		radix_sort(stack, &config->stats);
}
