#include "push_swap.h"

void	merge_sort(int *array, int size)
{
	int	mid;
	int	*left;
	int	*right;
	int	s[2];

	if (!array || size <= 1)
		return ;
	mid = size / 2;
	left = malloc(mid * sizeof(int));
	if (!left)
		return ;
	right = malloc((size - mid) * sizeof(int));
	if (!right)
		return (free(left));
	split_array(array, left, right, size);
	merge_sort(left, mid);
	merge_sort(right, (size - mid));
	s[0] = mid;
	s[1] = size - mid;
	merge(left, right, array, s);
	free(left);
	free(right);
}
