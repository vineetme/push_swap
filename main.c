/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:56:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/06 20:11:12 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"	

int	main(int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*stack_b;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (error());
		value = ft_atol(argv[i]);
		if (!is_number_in_range(value))
			return (error());
		i++;
	}
	if (has_duplicates(argc, argv))
		return (error());
	stack_b = build_stack(argc, argv);
	printf("B:\n");
	debug_printstack(stack_b);
	sb(&stack_b);
	printf("B after sb:\n");
	debug_printstack(stack_b);
	ra(&stack_b);
	printf("B after ra:\n");
	debug_printstack(stack_b);
	rra(&stack_b);
	printf("B after rra:\n");
	debug_printstack(stack_b);
	return (0);
}
