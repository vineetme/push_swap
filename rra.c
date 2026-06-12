/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:51 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:42:54 by vmeharia         ###   ########.fr       */
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

void	rra(t_node **a, t_statistics *stats)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	reverse_rotate_stack(a);
	if (!stats->silent)
		write(1, "rra\n", 4);
	stats->total_ops++;
	stats->rra_count++;
}
