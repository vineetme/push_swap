#include "push_swap.h"

void	merge(int *left, int *right, int *array, int size[2])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size[0] && j < size[1])
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < size[0])
		array[k++] = left[i++];
	while (j < size[1])
		array[k++] = right[j++];
}
