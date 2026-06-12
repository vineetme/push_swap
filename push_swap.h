/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 20:12:17 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/09 12:31:03 by kshalaba         ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}	t_node;

typedef enum e_strategy
{
	simple,
	medium,
	complex,
	adaptive
}	t_strategy;

typedef struct s_statistics
{
	float	disorder;
	int		total_ops;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
	int		silent;
	char	*strategy_name;
	char	*complexity_class;
}	t_statistics;

typedef struct s_config
{
	t_strategy		strategy;
	int				bench;
	int				first_number;
	int				strategy_set;
	t_statistics	stats;
	t_strategy		resolved_strategy;
}	t_config;

int			is_valid_number(char *str);
long		ft_atol(char *str);
int			is_number_in_range(long number);
int			error(void);
int			has_duplicates(int argc, char **argv, int start);
t_node		*new_node(int value);
t_node		*last_node(t_node *stack);
void		add_back(t_node **stack, t_node *new);
t_node		*build_stack(int argc, char **argv, int start);
void		debug_printstack(t_node *stack);
void		sa(t_node **a, t_statistics *stats);
void		sb(t_node **b, t_statistics *stats);
void		ss(t_node **a, t_node **b, t_statistics *stats);
void		pb(t_node **a, t_node **b, t_statistics *stats);
void		pa(t_node **b, t_node **a, t_statistics *stats);
void		ra(t_node **a, t_statistics *stats);
void		rb(t_node **b, t_statistics *stats);
void		rr(t_node **a, t_node **b, t_statistics *stats);
void		rra(t_node **a, t_statistics *stats);
void		rrb(t_node **b, t_statistics *stats);
void		rrr(t_node **a, t_node **b, t_statistics *stats);
int			is_sorted(t_node *stack);
void		sort_three(t_node **stack, t_statistics *stats);
void		sort_two(t_node **stash, t_statistics *stats);
t_node		*find_smallest(t_node *stack);
int			find_index(t_node *stack, t_node *node);
int			stack_size(t_node *stack);
void		move_smallest_to_top(t_node **stack, t_statistics *stats);
void		sort_four(t_node **a, t_statistics *stats);
void		sort_five(t_node **a, t_statistics *stats);
void		simple_sort(t_node **a, t_statistics *stats);
int			*stack_to_array(t_node *stack);
void		merge_sort(int *array, int size);
void		merge(int *left, int *right, int *array, int size[2]);
void		split_array(int *array, int *left, int *right, int size);
int			binary_search(int *array, int size, int value);
void		assign_indexes(t_node *stack);
int			parse_flags(int argc, char **argv, t_config *config);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
float		compute_disorder(t_node *stack);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putfloat_fd(float num, int fd);
void		init_statistics(t_statistics *stats);
void		resolve_strategy(t_config *config);
void		execute_strategy(t_node **stack, t_config *config);
void		print_benchmark(t_config *config);
int			ft_strlen(char *str);

#endif
