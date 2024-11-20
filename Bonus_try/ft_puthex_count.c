/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqz <sqz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:53:10 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 22:38:51 by sqz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putuhex_count(int *i, unsigned int u)
{
	char	*uhex_order;

	uhex_order = "0123456789ABCDEF";
	if (u < 16)
		ft_putchar_count(i, uhex_order[u]);
	else
	{
		ft_putuhex_count(i, u / 16);
		ft_putuhex_count(i, u % 16);
	}
}

static void	ft_putlhex_count(int *i, unsigned int u)
{
	char	*lhex_order;

	lhex_order = "0123456789abcdef";
	if (u < 16)
		ft_putchar_count(i, lhex_order[u]);
	else
	{
		ft_putlhex_count(i, u / 16);
		ft_putlhex_count(i, u % 16);
	}
}

void	ft_puthex_count(int *i, int sw, char c, unsigned int u)
{
	if (c == 'x' || c == 'X' || c == 'p')
	{
		if (sw == 1)
		{
			ft_putchar_count(i, '0');
			ft_putchar_count(i, c);
		}
		if (c == 'x')
			ft_putlhex_count(i, u);
		else
			ft_putuhex_count(i, u);
	}
}
