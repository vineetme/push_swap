/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:56:22 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:56:25 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_node *stack)
{
	t_node	*current;
	int		*array;
	int		i;

	array = malloc(stack_size(stack) * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}
