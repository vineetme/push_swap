/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:55:53 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/06 20:08:55 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node			*a;
	t_node			*b;
	t_statistics	stats;

	if (argc == 1)
		return (0);
	if (validate_inputs(argc, argv, 1))
		return (error());
	a = build_stack(argc, argv, 1);
	b = NULL;
	init_statistics(&stats);
	stats.silent = 1;
	read_instructions(&a, &b, &stats);
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
