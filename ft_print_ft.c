/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:12:33 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/30 11:47:22 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nb(char c)
{
	if (c == 'd' || c == 'i')
	{
		if (g_var.n == -2147483648)
		{
			write(1, "2147483648", 10);
			g_var.ret = g_var.ret + 10;
		}
		else
		{
			g_var.n = (g_var.n < 0) ? -g_var.n : g_var.n;
			ft_zero_prec_zero((unsigned int)g_var.n, 'd');
		}
	}
	else
		ft_zero_prec_zero(g_var.num, c);
}

void	ft_precesion_max(char *ptr)
{
	while (g_var.precesion > 0)
	{
		ft_put_char(*ptr);
		g_var.precesion--;
		ptr++;
	}
}

void	ft_width_max(char *ptr, int len)
{
	g_var.precesion1 = g_var.precesion;
	g_var.len1 = len;
	while (g_var.precesion1 > 0 && g_var.zero == -1 && g_var.len1-- > 0)
	{
		ft_put_char(*ptr);
		g_var.precesion1--;
		ptr++;
	}
	while (g_var.width > g_var.precesion)
	{
		ft_put_char(' ');
		g_var.width--;
	}
	while (g_var.precesion > len)
	{
		ft_put_char(' ');
		g_var.precesion--;
	}
	while (g_var.precesion > 0 && g_var.zero != -1)
	{
		ft_put_char(*ptr);
		g_var.precesion--;
		ptr++;
	}
}

void	ft_putchar_minus(void)
{
	if (g_var.sign == 1)
		ft_put_char('-');
}

void	ft_zero_prec_zero(unsigned int nb, char c)
{
	if (g_var.precesion == 0 && nb == 0 && g_var.width != 0)
		ft_put_char(' ');
	if (g_var.precesion != 0 || nb != 0)
	{
		if (c == 'd' || c == 'i')
			ft_put_nbr((int)nb);
		else
			ft_put_uxx(nb, c);
	}
}
