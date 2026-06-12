/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:42:13 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 12:42:15 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b, t_statistics *stats)
{
	t_node	*first;

	if (*a == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
	if (!stats->silent)
		write(1, "pb\n", 3);
	stats->total_ops++;
	stats->pb_count++;
}
