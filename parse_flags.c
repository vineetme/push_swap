#include "push_swap.h"

static void	init_config(t_config *config)
{
	config->strategy = adaptive;
	config->bench = 0;
	config->first_number = 1;
	config->strategy_set = 0;
}

static int	set_strategy(t_config *config, t_strategy strategy)
{
	if (config->strategy_set)
		return (1);
	config->strategy = strategy;
	config->strategy_set = 1;
	return (0);
}

static int	get_strategy(char *arg, t_strategy *strategy)
{
	if (!ft_strcmp(arg, "--simple"))
		*strategy = simple;
	else if (!ft_strcmp(arg, "--medium"))
		*strategy = medium;
	else if (!ft_strcmp(arg, "--complex"))
		*strategy = complex;
	else if (!ft_strcmp(arg, "--adaptive"))
		*strategy = adaptive;
	else
		return (0);
	return (1);
}

static int	handle_flag(t_config *config, char *arg)
{
	t_strategy	strategy;

	if (!ft_strcmp(arg, "--bench"))
	{
		if (config->bench)
			return (-1);
		config->bench = 1;
		return (1);
	}
	if (!get_strategy(arg, &strategy))
		return (0);
	if (set_strategy(config, strategy))
		return (-1);
	return (1);
}

int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;
	int	flag;

	init_config(config);
	i = 1;
	while (i < argc)
	{
		flag = handle_flag(config, argv[i]);
		if (flag == -1)
			return (error());
		if (flag == 0)
			break ;
		i++;
	}
	if (i < argc && !ft_strncmp(argv[i], "--", 2))
		return (error());
	if (i >= argc)
		return (error());
	config->first_number = i;
	return (0);
}
