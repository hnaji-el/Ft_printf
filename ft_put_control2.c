/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_control2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:55:33 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/28 22:46:21 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero2(int len, char c)
{
	while (g_var.precesion > len)
	{
		ft_put_char('0');
		g_var.precesion--;
	}
	ft_put_nb(c);
}

void	ft_put_zero_space2(int len, char c)
{
	if (g_var.precesion >= len)
	{
		while (g_var.precesion > len)
		{
			ft_put_char('0');
			len++;
		}
		ft_put_nb(c);
		while (g_var.width > g_var.precesion)
		{
			ft_put_char(' ');
			g_var.width--;
		}
	}
	else
	{
		ft_put_nb(c);
		while (g_var.width > len)
		{
			ft_put_char(' ');
			g_var.width--;
		}
	}
}

void	ft_putddd2(int nb, char c)
{
	int		len;

	g_var.n = nb;
	len = (nb == 0) ? ft_numb_dd(nb) : ft_numb_dd(nb) - 1;
	if (g_var.precesion >= g_var.width)
	{
		if (nb < 0)
			ft_put_char('-');
		ft_put_zero2(len, c);
	}
	else
	{
		g_var.sign = (nb < 0) ? 1 : g_var.sign;
		if (g_var.sign == 1)
		{
			g_var.width--;
			ft_put_char('-');
		}
		ft_put_zero_space2(len, c);
	}
}

void	ft_putuuu2(unsigned int nb, char c)
{
	int		len;

	g_var.num = nb;
	len = 1;
	if (nb > 0)
		len = ft_numb_ux(nb, c);
	if (g_var.precesion >= g_var.width)
		ft_put_zero2(len, c);
	else
		ft_put_zero_space2(len, c);
}
