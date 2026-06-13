/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:55:18 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:55:21 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	highest_index;
	int	max_bits_needed;

	max_bits_needed = 1;
	highest_index = stack_size(stack) - 1;
	while ((highest_index / 2) > 0)
	{
		max_bits_needed++;
		highest_index = highest_index / 2;
	}
	return (max_bits_needed);
}

static void	process_bit(t_node **a, t_node **b, int bit, t_statistics *stats)
{
	int	size;

	size = stack_size(*a);
	while (size != 0)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			pb(a, b, stats);
		else
			ra(a, stats);
		size--;
	}
}

static void	restore_stack(t_node **a, t_node **b, t_statistics *stats)
{
	while (*b != NULL)
		pa(b, a, stats);
}

void	radix_sort(t_node **a, t_statistics *stats)
{
	t_node	*b;
	int		max_bits;
	int		bit;

	b = NULL;
	bit = 0;
	max_bits = get_max_bits(*a);
	while (bit < max_bits)
	{
		process_bit(a, &b, bit, stats);
		restore_stack(a, &b, stats);
		bit++;
	}
}
