/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqz <sqz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:51:19 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 22:47:18 by sqz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static void	specifier_handler(int *count, int sw, char c, va_list p2)
{
	if (c == 'x' || c == 'X')
		ft_puthex_count(count, sw, c, va_arg(p2, unsigned int));
}

static int	is_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'x' || c == 'X');
}

static int is_flag(char c)
{
	return (c == '#' || c == ' ' || c == '+');
}

static void	str_iter(const char *ptr, va_list p, int *count)
{
	// i was passing the whole address so i could
	// increment the address and pass the format specifier
	// from this function to specifier handler
	int sw;

	sw = 0;
	if (is_specifier(*ptr))
		specifier_handler(count, sw, *ptr, p);
	else if (is_flag(*ptr))
	{
		if (*ptr++ == '#')
		{
			sw = 1;
			specifier_handler(count, sw, *ptr, p);
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		count;
	int		i;

	va_start(p, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')

			ft_putchar_count(&count, str[i]);
		else
		{
			i++;
			if (!str[i])
				break ;
			str_iter(&str[i], p, &count);
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	va_end(p);
	return (count);
}


int main()
{
	ft_printf("hello%#x", 123);
	// it prints x at the end, spent more time trying to handle it
	// took off so that i could save days for big projects
	return (0);
}
