/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:59:57 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:59:59 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_array(int *array, int *left, int *right, int size)
{
	int	i;
	int	mid;

	mid = size / 2;
	i = -1;
	while (++i < mid)
		left[i] = array[i];
	i = -1;
	while (++i < size - mid)
		right[i] = array[mid + i];
}
