/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:49:39 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 00:49:43 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node **stack, t_node *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last_node(*stack)->next = new;
}
