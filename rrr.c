/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:43:09 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:43:11 by vmeharia         ###   ########.fr       */
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

void	rrr(t_node **a, t_node **b, t_statistics *stats)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (!stats->silent)
		write(1, "rrr\n", 4);
	stats->total_ops++;
	stats->rrr_count++;
}
