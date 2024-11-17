#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	specifier_handle(size_t *count, char c, va_list p2)
{
	char	cha;

	if (c == '\0')
		return ;
	else if (c == 'c')
	{
		cha = va_arg(p2, int);
		ft_putchar(cha);
		*count++;
	}
}


static int	count_elements(const char *ptr, va_list p)
{
	size_t	i;
	size_t	count;

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
			{
				specifier_handle(&count , ptr[i], p);
				count++;
			}

		}
		// printf("char: [%c] and i %d", *(ptr + i), i);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list p;

	va_start(p, str);
	count = count_elements(str, p);
	va_end(p);
	return (count);
}

int main(int ac, char **av)
{
	printf("mine %d", ft_printf("hello %c%c%c%c", 'a', 'b', 'c', 'd'));
	printf("real %d", printf("hello %c%c%c%c", 'a', 'b', 'c', 'd'));
	return (0);
}