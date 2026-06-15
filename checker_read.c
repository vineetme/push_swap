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
#include "get_next_line.h"

void	read_instructions(t_node **a, t_node **b, t_statistics *stats)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_instructions(line, a, b, stats))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}
