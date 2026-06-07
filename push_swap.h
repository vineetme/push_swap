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

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

int		is_valid_number(char *str);
long	ft_atol(char *str);
int		is_number_in_range(long number);
int		error(void);
int		has_duplicates(int argc, char **argv);
t_node	*new_node(int value);
t_node	*last_node(t_node *stack);
void	add_back(t_node **stack, t_node *new);
t_node	*build_stack(int argc, char **argv);
void	debug_printstack(t_node *stack);
void	sa(t_node **stack);

#endif
