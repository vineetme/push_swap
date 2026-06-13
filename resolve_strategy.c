/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:59:36 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:59:38 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	resolve_adaptive_strategy(t_config *config)
{
	if (config->stats.disorder < 20.0)
	{
		config->resolved_strategy = simple;
		config->stats.strategy_name = "Adaptive";
		config->stats.complexity_class = "O(n²)";
	}
	else if (config->stats.disorder < 50.0)
	{
		config->resolved_strategy = medium;
		config->stats.strategy_name = "Adaptive";
		config->stats.complexity_class = "O(n√n)";
	}
	else
	{
		config->resolved_strategy = complex;
		config->stats.strategy_name = "Adaptive";
		config->stats.complexity_class = "O(n log n)";
	}
}

void	resolve_strategy(t_config *config)
{
	if (config->strategy == simple)
	{
		config->resolved_strategy = simple;
		config->stats.strategy_name = "Simple";
		config->stats.complexity_class = "O(n²)";
	}
	else if (config->strategy == medium)
	{
		config->resolved_strategy = medium;
		config->stats.strategy_name = "Medium";
		config->stats.complexity_class = "O(n√n)";
	}
	else if (config->strategy == complex)
	{
		config->resolved_strategy = complex;
		config->stats.strategy_name = "Complex";
		config->stats.complexity_class = "O(n log n)";
	}
	else
		resolve_adaptive_strategy(config);
}
