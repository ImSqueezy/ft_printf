#include "printf.h"

static void	specifier_handler(int *count, char c, va_list p2)
{
	if (c == '\0')
		return ;
	else if (c == 's')
		ft_putstr_count(count, va_arg(p2, char *));
	else if (c == 'c')
		ft_putchar_count(count, va_arg(p2, int));
	else if (c == '%')
		ft_putchar_count(count, c);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count(count, va_arg(p2, int));
	else if (c == 'u')
		ft_putu_count(count, va_arg(p2, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_puthex_count(count, c, va_arg(p2, unsigned int));
	// else if (c == 'p')
	// 	ft_pu
}


static int	count_elements(const char *ptr, va_list p)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] != '%')
		{
			write(1, &ptr[i], 1);
			count++;
		}
		else
		{
			i++;
			if (ptr[i])
				specifier_handler(&count, ptr[i], p);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int 	count;
	va_list p;

	va_start(p, str);
	count = count_elements(str, p);
	va_end(p);
	return (count);
}

#include <stdio.h>
#include <string.h>
int main()
{
	printf("[%d]", printf("hello %s %% %X\n", "hello world!", -2));
	printf("[%d]", ft_printf("hello %s %% %X\n", "hello world!", -2));
	return (0);
}