#include "printf.h"

void	ft_putchar_count(int *i, char c)
{
	write(1, &c, 1);
	(*i)++;
}
