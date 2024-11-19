#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_count(int *i, char c);
void	ft_putstr_count(int	*i, char *s);
void	ft_putnbr_count(int	*i, int nbr);
void	ft_putu_count(int *i, unsigned int u);
void	ft_puthex_count(int *i, char c, unsigned int u);
void	ft_putptr_count(int *i, void *p);

#endif
