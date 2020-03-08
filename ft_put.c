/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:41:49 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/27 16:57:50 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(char c)
{
	write(1, &c, 1);
	g_var.ret++;
}

void	ft_put_str(char *str)
{
	while (*str)
		ft_put_char(*str++);
}

void	ft_put_nbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_put_char('-');
		n = nb * (-1);
	}
	else
		n = nb;
	if (n < 10)
		ft_put_char(n + 48);
	else
	{
		ft_put_nbr(n / 10);
		ft_put_char(n % 10 + 48);
	}
}

void	ft_put_uxx(unsigned int nb, char c)
{
	char			*base;
	unsigned int	n;

	n = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'u')
	{
		base = "0123456789";
		n = 10;
	}
	if (nb < n)
		ft_put_char(base[nb % n]);
	else
	{
		ft_put_uxx(nb / n, c);
		ft_put_char(base[nb % n]);
	}
}

void	ft_put_add(unsigned long long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
	{
		ft_put_str("0x");
		ft_put_char(base[nb % 16]);
	}
	else
	{
		ft_put_add(nb / 16);
		ft_put_char(base[nb % 16]);
	}
}
