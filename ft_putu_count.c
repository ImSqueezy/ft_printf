#include "printf.h"

void	ft_putu_count(int *i, unsigned int u)
{
	char	a;

	if (u <= 9)
	{
		a = u + 48;
		ft_putchar_count(i, a);
	}
	else
	{
		ft_putu_count(i, u / 10);
		ft_putu_count(i, u % 10);
	}
}
