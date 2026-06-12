#include "push_swap.h"

void	ft_putfloat_fd(float num, int fd)
{
	int	int_part;
	int	frac_part;

	int_part = (int)num;
	frac_part = (int)((num - (float)int_part) * 100.0f + 0.5f);
	if (frac_part >= 100)
	{
		int_part++;
		frac_part = 0;
	}
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	ft_putchar_fd(((frac_part / 10) + '0'), fd);
	ft_putchar_fd(((frac_part % 10) + '0'), fd);
	ft_putchar_fd(('%'), fd);
	ft_putchar_fd(('\n'), fd);
}
