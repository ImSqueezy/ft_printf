#include "printf.h"

void	ft_putstr_count(int	*i, char *s)
{
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar_count(i, *s++);
}
