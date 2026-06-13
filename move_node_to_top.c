/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:56:06 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:56:10 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_to_top(t_node **stack, t_node *target, t_statistics *stats)
{
	int	mid;
	int	position;

	mid = stack_size(*stack) / 2;
	position = find_index(*stack, target);
	if (position <= mid)
	{
		while (*stack != target)
			ra(stack, stats);
	}
	else
	{
		while (*stack != target)
			rra(stack, stats);
	}
}
