/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:59 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:43:01 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*last;
	t_node	*penultimate;
	t_node	*current;

	current = *stack;
	last = last_node(*stack);
	while (current->next->next != NULL)
		current = current->next;
	penultimate = current;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_node **b, t_statistics *stats)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	reverse_rotate_stack(b);
	if (!stats->silent)
		write(1, "rrb\n", 4);
	stats->total_ops++;
	stats->rrb_count++;
}
