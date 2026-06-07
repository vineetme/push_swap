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

void	rrb(t_node **b)
{
	t_node	*current;
	t_node	*last;
	t_node	*penultimate;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	current = *b;
	last = last_node(*b);
	while (current->next->next != NULL)
		current = current->next;
	penultimate = current;
	penultimate->next = NULL;
	last->next = *b;
	*b = last;
}
