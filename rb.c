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

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	first = *b;
	last = last_node(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
}
