/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:49:51 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/07 00:49:53 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*build_input_stack(int argc, char **argv, int start)
{
	char	**split;
	t_node	*stack;
	int		count;

	if (argc - start != 1)
	{
		if (validate_inputs(argc, argv, start))
			return (NULL);
		return (build_stack(argc, argv, start));
	}
	split = ft_split(argv[start], ' ');
	if (!split)
		return (NULL);
	count = split_count(split);
	if (count == 0 || validate_inputs(count, split, 0))
		return (free_split(split), NULL);
	stack = build_stack(count, split, 0);
	free_split(split);
	return (stack);
}
