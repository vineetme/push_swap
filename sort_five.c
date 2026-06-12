/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:25:31 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/08 13:25:36 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_node **a, t_statistics *stats)
{
	t_node	*b;

	b = NULL;
	move_smallest_to_top(a, stats);
	pb(a, &b, stats);
	sort_four(a, stats);
	pa(&b, a, stats);
}
