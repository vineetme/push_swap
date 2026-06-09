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

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = last_node(*a);
	last->next = first;
	write(1, "ra\n", 3);
}
