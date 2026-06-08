/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:25:16 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/08 13:25:20 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_node **a)
{
	(void)ops;
	t_node	*b;

	b = NULL;
	while (stack_size(*a) > 5)
	{
		move_smallest_to_top(a);
		pb (a, &b);
	}
	sort_five(a);
	while (b != NULL)
		pa(&b, a);
}
