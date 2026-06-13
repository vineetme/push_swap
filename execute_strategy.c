/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 23:00:18 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 23:00:20 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_strategy(t_node **stack, t_config *config)
{
	if (config->resolved_strategy == simple)
		simple_sort(stack, &config->stats);
	else if (config->resolved_strategy == medium)
		chunk_sort(stack, &config->stats);
	else if (config->resolved_strategy == complex)
		radix_sort(stack, &config->stats);
}
