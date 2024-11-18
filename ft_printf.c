#include "printf.h"

static void	specifier_handle(int *count, char c, va_list p2)
{
	if (c == '\0')
		return ;
	else if (c == 'c')
		ft_putchar_count(count, va_arg(p2, int));
	else if (c == 's')
		ft_putstr_count(count, va_arg(p2, char *));
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
				specifier_handle(&count , ptr[i], p);
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
	printf("length %zu\n", strlen("hello hello \nworld! a"));
	ft_printf("hello %s %c\n", "hello world!", 'a');
	return (0);
}