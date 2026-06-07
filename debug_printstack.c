/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:50:00 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 00:50:20 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	debug_printstack(t_node *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
