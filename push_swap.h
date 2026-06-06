/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:12:17 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/06 20:13:03 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

int		is_valid_number(char *str);
long	ft_atol(char *str);
int		is_number_in_range(long number);
int		error(void);
int		has_duplicates(int argc, char **argv);

#endif
