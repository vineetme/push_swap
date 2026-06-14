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
	t_config		config;
	int				i;
	long			value;
	t_node			*stack;
//	t_node			*current;

	if (argc == 1)
		return (0);
	init_statistics(&config.stats);

	if (parse_flags(argc, argv, &config))
		return (1);

	config.stats.silent = config.bench;

	i = config.first_number;
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
	
//	printf("Stack:\n");
//	debug_printstack(stack);

	assign_indexes(stack);

//	printf("After assign_indexes:\n");
//	current = stack;
//	while (current)
//	{
//		printf("%d -> %d\n", current->value, current->index);
//		current = current->next;
//	}

	config.stats.disorder = compute_disorder(stack);

//	write(1, "Disorder: ", 10);
//	ft_putfloat_fd((config.stats.disorder), 2);

	resolve_strategy(&config);

//	printf("resolved strategy = %d\n", config.resolved_strategy);
//	printf("strategy name = %s\n", config.stats.strategy_name);
//	printf("complexity class = %s\n", config.stats.complexity_class);

	execute_strategy(&stack, &config);

	printf("Stack after applying strategy:\n");
	debug_printstack(stack);

	if (config.bench)
		print_benchmark(&config);

//	printf("total_ops = %d\n", config.stats.total_ops);
//	printf("sa = %d\n", config.stats.sa_count);
//	printf("pb = %d\n", config.stats.pb_count);
//	printf("ra = %d\n", config.stats.ra_count);

	free_stack(&stack);
	return (0);
}
