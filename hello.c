#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_c(char	c, va_list p2)
{
	va_list x;
	char	cha;
	va_copy(x, p2);
	if (c == '\n')
		return ;
	else if (c == 'c')
	{
		cha = va_arg(x, int);
		ft_putchar(cha);
	}
}


int	ft_printf(const char *a, ...)
{
	void	*ptr;
	va_list p;
	int		i;
	int		count;

	va_start(p, a);
	i = 0;
	count = 0;
	while (a[i])
	{
		if (a[i] != '%')
		{
			write(1, &a[i], 1);
			count++;
		}
		else
		{
			i++;
			if (a[i])
			{
				ft_c(a[i], p);
				i++;
			}
		}
		i++;
	}
	va_end(p);
	return (count);
}

int main(int ac, char **av)
{
	ft_printf("hello %c world\n", 'c');
	printf("hello %c world\n", 'c');
	return (0);
}