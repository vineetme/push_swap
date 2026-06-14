/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:49:51 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 00:49:53 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_top(t_node **b, t_node *target, t_statistics *stats)
{
	int	mid;
	int	position;

	mid = stack_size(*b) / 2;
	position = find_index(*b, target);
	if (position <= mid)
	{
		while (*b != target)
			rb(b, stats);
	}
	else
	{
		while (*b != target)
			rrb(b, stats);
	}
}
