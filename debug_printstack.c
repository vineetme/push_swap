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

void	debug_printstack(int argc, char **argv)
{
	t_node	*ptr;

	ptr = build_stack(argc, argv);
	while (ptr != NULL)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}
