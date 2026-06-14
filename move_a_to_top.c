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

void	move_a_to_top(t_node **a, t_node *target, t_statistics *stats)
{
	int	mid;
	int	position;

	mid = stack_size(*a) / 2;
	position = find_index(*a, target);
	if (position <= mid)
	{
		while (*a != target)
			ra(a, stats);
	}
	else
	{
		while (*a != target)
			rra(a, stats);
	}
}
