#include "push_swap.h"

int	is_number_in_range(long number)
{
	if (number <= INT_MAX && number >= INT_MIN)
		return (1);
	return (0);
}
