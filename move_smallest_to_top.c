/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_smallest_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:00:51 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 19:02:24 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_smallest_to_top(t_node **stack)
{
	t_node	*smallest;
	int		index;
	int		size;

	smallest = find_smallest(*stack);
	index = find_index(*stack, smallest);
	size = stack_size(*stack);
	if (index <= size / 2)
	{
		while (*stack != smallest)
			ra(stack);
	}
	else
	{
		while (*stack != smallest)
			rra(stack);
	}
}
