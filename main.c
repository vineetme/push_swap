/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:56:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/14 16:48:35 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

static int	validate_inputs(int argc, char **argv, int start_index)
{
	int		i;
	long	value;

	i = start_index;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (1);
		value = ft_atol(argv[i]);
		if (!is_number_in_range(value))
			return (1);
		i++;
	}
	if (has_duplicates(argc, argv, start_index))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config		config;
	t_node			*stack;

	if (argc == 1)
		return (0);
	init_statistics(&config.stats);
	if (parse_flags(argc, argv, &config))
		return (1);
	config.stats.silent = config.bench;
	if (validate_inputs(argc, argv, config.first_number))
		return (error());
	stack = build_stack(argc, argv, config.first_number);
	assign_indexes(stack);
	config.stats.disorder = compute_disorder(stack);
	resolve_strategy(&config);
	execute_strategy(&stack, &config);
	if (config.bench)
		print_benchmark(&config);
	free_stack(&stack);
	return (0);
}
