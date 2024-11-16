#include <stdio.h>
#include <stdarg.h>

int max(int n, ...)
{
	va_list args;
	int		i;
	int		max;

	max = n;
	va_start(args, n);
	i = 0;
	while (i < n)
	{
		int tmp = va_arg(args, int);
		printf("tmp %d\n", tmp);
		if (tmp > max)
			max = tmp;
		i++;
	}
	va_end(args);
	return (max);
}

int main(int ac, char **av)
{
	printf("%d\n", max(4, 2, 5, 0, 9));
	return (0);
}