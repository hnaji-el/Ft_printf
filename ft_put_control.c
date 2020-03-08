/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:57:44 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/29 22:28:22 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putddd(int nb)
{
	int		len;

	g_var.n = nb;
	len = (nb > 0) ? ft_numb_dd(nb) - 1 : ft_numb_dd(nb);
	if (g_var.zero == 1 && nb < 0)
		ft_put_char('-');
	if (g_var.zero == -1)
		ft_put_nbr(nb);
	while (g_var.width > len)
	{
		if (g_var.zero == 0 || g_var.zero == -1)
			ft_put_char(' ');
		else
			ft_put_char('0');
		g_var.width--;
	}
	if (g_var.zero == 0)
		ft_put_nbr(nb);
	if (g_var.zero == 1)
	{
		g_var.precesion = 1;
		ft_put_nb('d');
	}
}

void	ft_putuuu(unsigned int nb, char c)
{
	int		len;

	len = 1;
	if (nb > 0)
		len = ft_numb_ux(nb, c);
	if (g_var.zero == -1)
		ft_put_uxx(nb, c);
	while (g_var.width > len)
	{
		if (g_var.zero == 0 || g_var.zero == -1)
			ft_put_char(' ');
		else
			ft_put_char('0');
		g_var.width--;
	}
	if (g_var.zero != -1)
		ft_put_uxx(nb, c);
}

void	ft_putccc(va_list list, char c)
{
	if (g_var.zero == -1)
	{
		if (c == 'c')
			ft_put_char(va_arg(list, int));
		else
			ft_put_char(c);
	}
	while (g_var.width > 1)
	{
		if (g_var.zero == 0 || g_var.zero == -1)
			ft_put_char(' ');
		else
			ft_put_char('0');
		g_var.width--;
	}
	if (g_var.zero != -1)
	{
		if (c == 'c')
			ft_put_char(va_arg(list, int));
		else
			ft_put_char(c);
	}
}

void	ft_putsss(char *ptr)
{
	int		len;

	if (!ptr)
		ptr = "(null)";
	len = ft_strlen(ptr);
	if (g_var.zero == -1)
		ft_put_str(ptr);
	while (g_var.width > len)
	{
		ft_put_char(' ');
		g_var.width--;
	}
	if (g_var.zero == 0)
		ft_put_str(ptr);
}

void	ft_putppp(unsigned long long nb)
{
	int		len;

	len = (g_var.point == 1) ? 2 : 3;
	if (nb > 0)
		len = ft_numb_pp(nb);
	if (g_var.zero == -1)
	{
		if (g_var.point == 1 && nb == 0)
			ft_put_str("0x");
		else
			ft_put_add(nb);
	}
	while (g_var.width > len)
	{
		ft_put_char(' ');
		g_var.width--;
	}
	if (g_var.zero == 0)
	{
		if (g_var.point == 1 && nb == 0)
			ft_put_str("0x");
		else
			ft_put_add(nb);
	}
}
