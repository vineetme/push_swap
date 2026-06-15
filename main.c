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

int	main(int argc, char **argv)
{
	t_config		config;
	t_node			*stack;

	if (argc == 1)
		return (0);
	init_statistics(&config.stats);
	if (parse_flags(argc, argv, &config))
		return (1);
	config.stats.silent = 0;
	stack = build_input_stack(argc, argv, config.first_number);
	if (!stack)
		return (error());
	assign_indexes(stack);
	config.stats.disorder = compute_disorder(stack);
	resolve_strategy(&config);
	execute_strategy(&stack, &config);
	if (config.bench)
		print_benchmark(&config);
	free_stack(&stack);
	return (0);
}
