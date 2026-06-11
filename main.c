/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:56:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 19:09:40 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"	

int	main(int argc, char **argv)
{
	t_config	config;
	int			i;
	long		value;
	t_node		*stack;
	t_node		*current;

	if (parse_flags(argc, argv, &config))
		return (1);

	i = config.first_number;
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
	if (has_duplicates(argc, argv, config.first_number))
		return (error());
	stack = build_stack(argc, argv, config.first_number);
	assign_indexes(stack);
	printf("After assign_indexes:\n");
	current = stack;
	while (current)
	{
		printf("%d -> %d\n", current->value, current->index);
		current = current->next;
	}	
	printf("Stack:\n");
	debug_printstack(stack);
	simple_sort(&stack);
	printf("Stack after simple_sort:\n");
	debug_printstack(stack);
	return (0);
}
