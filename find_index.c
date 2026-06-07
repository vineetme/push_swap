/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:59:24 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 18:59:26 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_node *stack, t_node *node)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack == node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
