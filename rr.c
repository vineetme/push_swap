/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:33:20 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 14:33:27 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = last_node(*stack);
	last->next = first;
}

void	rr(t_node **a, t_node **b, t_statistics *stats)
{
	if (*a && (*a)->next)
		rotate_stack(a);
	if (*b && (*b)->next)
		rotate_stack(b);
	if (!stats->silent)
		write(1, "rr\n", 3);
	stats->total_ops++;
	stats->rr_count++;
}
