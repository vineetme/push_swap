/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:58:37 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/13 22:58:39 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_benchmark_header(t_config *config)
{
	write(2, "[bench] disorder: ", 18);
	ft_putfloat_fd(config->stats.disorder, 2);
	write(2, "[bench] strategy: ", 18);
	write(2, config->stats.strategy_name,
		ft_strlen(config->stats.strategy_name));
	write(2, " / ", 3);
	write(2, config->stats.complexity_class,
		ft_strlen(config->stats.complexity_class));
	write(2, "\n", 1);
}

static void	print_benchmark_totals(t_config *config)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(config->stats.total_ops, 2);
	write(2, "\n", 1);
}

static void	print_swap_push(t_config *config)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(config->stats.sa_count, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(config->stats.sb_count, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(config->stats.ss_count, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(config->stats.pa_count, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(config->stats.pb_count, 2);
	write(2, "\n", 1);
}

static void	print_rotate(t_config *config)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr_fd(config->stats.ra_count, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(config->stats.rb_count, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(config->stats.rr_count, 2);
	write(2, "  rra: ", 7);
	ft_putnbr_fd(config->stats.rra_count, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(config->stats.rrb_count, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(config->stats.rrr_count, 2);
	write(2, "\n", 1);
}

void	print_benchmark(t_config *config)
{
	print_benchmark_header(config);
	print_benchmark_totals(config);
	print_swap_push(config);
	print_rotate(config);
}
