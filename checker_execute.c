/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:55:53 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/06 20:08:55 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_swap_push(char *line, t_node **a, t_node **b,
	t_statistics *stats)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, stats);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, stats);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, stats);
	else if (!ft_strcmp(line, "pa\n"))
		pa(b, a, stats);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, stats);
	else
		return (0);
	return (1);
}

static int	execute_rotate(char *line, t_node **a, t_node **b,
	t_statistics *stats)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a, stats);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, stats);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, stats);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, stats);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, stats);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, stats);
	else
		return (0);
	return (1);
}

int	execute_instructions(char *line, t_node **a, t_node **b,
	t_statistics *stats)
{
	if (execute_swap_push(line, a, b, stats))
		return (1);
	if (execute_rotate(line, a, b, stats))
		return (1);
	return (0);
}
