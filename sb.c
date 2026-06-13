/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:43:23 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:43:25 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sb(t_node **b, t_statistics *stats)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	swap_stack(b);
	if (!stats->silent)
		write(1, "sb\n", 3);
	stats->total_ops++;
	stats->sb_count++;
}
