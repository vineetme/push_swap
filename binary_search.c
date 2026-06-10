#include "push_swap.h"

int	binary_search(int *array, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (array[mid] == value)
			return (mid);
		if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
