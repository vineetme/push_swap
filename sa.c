/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 07:23:04 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 07:23:07 by vmeharia         ###   ########.fr       */
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

void	sa(t_node **a, t_statistics *stats)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	swap_stack(a);
	if (!stats->silent)
		write(1, "sa\n", 3);
	stats->total_ops++;
	stats->sa_count++;
}
