/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_control1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:09:58 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/28 21:32:37 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero(int len)
{
	while (g_var.precesion > len)
	{
		ft_put_char('0');
		g_var.precesion--;
	}
}

void	ft_put_zero_space(int len)
{
	if (g_var.sign == 1)
		g_var.width--;
	if (g_var.precesion >= len)
	{
		while (g_var.width > g_var.precesion)
		{
			ft_put_char(' ');
			g_var.width--;
		}
		ft_putchar_minus();
		while (g_var.precesion > len)
		{
			ft_put_char('0');
			g_var.precesion--;
		}
	}
	else
	{
		while (g_var.width > len)
		{
			ft_put_char(' ');
			g_var.width--;
		}
		ft_putchar_minus();
	}
}

void	ft_putddd1(int nb)
{
	int		len;

	len = (nb == 0) ? ft_numb_dd(nb) : ft_numb_dd(nb) - 1;
	if (g_var.precesion >= g_var.width)
	{
		if (nb < 0)
			ft_put_char('-');
		ft_put_zero(len);
	}
	else
	{
		g_var.sign = (nb < 0) ? 1 : g_var.sign;
		ft_put_zero_space(len);
	}
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		g_var.ret = g_var.ret + 10;
	}
	else
	{
		nb = (nb < 0) ? -nb : nb;
		ft_zero_prec_zero((unsigned int)nb, 'd');
	}
}

void	ft_putuuu1(unsigned int nb, char c)
{
	int		len;

	len = 1;
	if (nb > 0)
		len = ft_numb_ux(nb, c);
	if (g_var.precesion >= g_var.width)
		ft_put_zero(len);
	else
		ft_put_zero_space(len);
	ft_zero_prec_zero(nb, c);
}

void	ft_putsss1(char *ptr)
{
	int		len;

	if (!ptr)
		ptr = "(null)";
	len = ft_strlen(ptr);
	if (g_var.precesion < 0)
		ft_putsss(ptr);
	else
	{
		if (g_var.width >= g_var.precesion)
			ft_width_max(ptr, len);
		else
		{
			if (len <= g_var.precesion)
				ft_putsss(ptr);
			else
				ft_precesion_max(ptr);
		}
	}
}
