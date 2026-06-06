#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	long num;
	int	sign;
	
	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = sign * num;
	return (num);
}
/*
#include <stdio.h>

int main()
{
	printf("%ld\n", ft_atol("-3456"));
}
*/
		

