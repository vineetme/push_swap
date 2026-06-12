/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:23 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:42:25 by vmeharia         ###   ########.fr       */
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

void	ra(t_node **a, t_statistics *stats)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	rotate_stack(a);
	write(1, "ra\n", 3);
	stats->total_ops++;
	stats->ra_count++;
}
