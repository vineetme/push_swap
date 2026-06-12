/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:43:32 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:43:34 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ss(t_node **a, t_node **b, t_statistics *stats)
{
	swap_stack(a);
	swap_stack(b);
	if (!stats->silent)
		write(1, "ss\n", 3);
	stats->total_ops++;
	stats->ss_count++;
}
