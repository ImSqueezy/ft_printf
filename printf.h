#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h> // temporarly

void	ft_putchar_count(int *i, char c);
void	ft_putstr_count(int	*i, char *s);
void	ft_putnbr_count(int	*i, int nbr);

#endif
