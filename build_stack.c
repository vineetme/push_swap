/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:49:51 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 00:49:53 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*build_stack(int argc, char **argv, int start)
{
	int		i;
	t_node	*stack;
	t_node	*new;

	i = start;
	stack = new_node(ft_atol(argv[i]));
	i++;
	while (i < argc)
	{
		new = new_node(ft_atol(argv[i]));
		add_back(&stack, new);
		i++;
	}
	return (stack);
}
