/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:01:18 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 19:01:20 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_node **a)
{
	t_node	*b;

	b = NULL;
	move_smallest_to_top(a);
	pb(a, &b);
	sort_three(a);
	pa(&b, a);
}
