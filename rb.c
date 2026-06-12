/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:32 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:42:34 by vmeharia         ###   ########.fr       */
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

void	rb(t_node **b, t_statistics *stats)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	rotate_stack(b);
	if (!stats->silent)
		write(1, "rb\n", 3);
	stats->total_ops++;
	stats->rb_count++;
}
