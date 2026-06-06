/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:56:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/06 15:56:25 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"	

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc && is_valid_number(argv[i]))
			i++;
	if (i == argc)
	{
		i = 1;
		while (i < argc)
		{
			printf("%ld\n", ft_atol(argv[i]));
			i++;
		}
	}
	else		
		write(2, "error\n", 6);
}
