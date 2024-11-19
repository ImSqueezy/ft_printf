#include "printf.h"

void	ft_putptr_count(int *i, void *p)
{
	unsigned long	address;
	char			*hex_order = "0123456789abcdef";

	address = (unsigned long)p;
	if (!address)
		ft_putchar_count(i, '0');
	else if (address < 16)
		ft_putchar_count(i, hex_order[address]);
	else
	{
		
		ft_putptr_count(i, (void *)(address / 16));
		ft_putchar_count(i, hex_order[address % 16]);
	}
}
