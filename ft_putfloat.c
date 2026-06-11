#include "push_swap.h"

static void	ft_putchar(char c) {
    write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}

void	ft_putfloat(float num)
{
	int int_part;
	int frac_part;

	int_part = (int)num;
    frac_part = (int)((num - (float)int_part) * 100.0f + 0.5f);
    if (frac_part >= 100)
	{
		int_part++;
		frac_part = 0;
    }
    ft_putnbr(int_part);
    ft_putchar('.');
    ft_putchar((frac_part / 10) + '0');
    ft_putchar((frac_part % 10) + '0');
	ft_putchar('\n');
}
