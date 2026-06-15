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

int	validate_inputs(int argc, char **argv, int start_index)
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
