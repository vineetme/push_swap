/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:03 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:42:06 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **b, t_node **a, t_statistics *stats)
{
	t_node	*first;

	if (*b == NULL)
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
	write(1, "pa\n", 3);
	stats->total_ops++;
	stats->pa_count++;
}
