/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:44:05 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 16:44:08 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack, t_statistics *stats)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = ((*stack)->next)->value;
	third = ((*stack)->next->next)->value;
	if (first < second && second < third && third > first)
		return ;
	else if (first < second && second > third && third > first)
	{
		rra(stack, stats);
		sa(stack, stats);
	}
	else if (first > second && second < third && third > first)
		sa(stack, stats);
	else if (first < second && second > third && third < first)
		rra(stack, stats);
	else if (first > second && second < third && third < first)
		ra(stack, stats);
	else
	{
		ra(stack, stats);
		sa(stack, stats);
	}
}
