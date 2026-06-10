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
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) == 2)
		return (sort_two(a));
	if (stack_size(*a) == 3)
		return (sort_three(a));
	if (stack_size(*a) == 4)
		return (sort_four(a));
	else
	{
		while (stack_size(*a) > 5)
		{
			move_smallest_to_top(a);
			pb (a, &b);
		}
		sort_five(a);
		while (b != NULL)
			pa(&b, a);
	}
}
