/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:57:40 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:57:42 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_node **a, t_statistics *stats)
{
	t_node	*b;

	if (stack_size(*a) <= 5)
	{
		simple_sort(a, stats);
		return ;
	}
	b = NULL;
	push_chunk_to_b(a, &b, stats);
	restore_from_b(a, &b, stats);
}
