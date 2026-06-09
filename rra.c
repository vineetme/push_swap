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

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*penultimate;
	t_node	*current;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	current = *a;
	last = last_node(*a);
	while (current->next->next != NULL)
		current = current->next;
	penultimate = current;
	penultimate->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
