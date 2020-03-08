/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:11:00 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/29 23:03:27 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_control(const char **format, va_list list)
{
	if (**format == 'd' || **format == 'i')
		ft_putddd(va_arg(list, int));
	if (**format == 'c' || **format == '%')
		ft_putccc(list, **format);
	if (**format == 's')
		ft_putsss(va_arg(list, char *));
	if (**format == 'u' || **format == 'x' || **format == 'X')
		ft_putuuu(va_arg(list, unsigned int), **format);
	if (**format == 'p')
		ft_putppp(va_arg(list, unsigned long long));
}

void	ft_control1(const char **format, va_list list)
{
	if (**format == 'd' || **format == 'i')
		ft_d(format, list);
	if (**format == 'u' || **format == 'x' || **format == 'X')
	{
		if (g_var.precesion < 0)
			ft_putuuu(va_arg(list, unsigned int), **format);
		else
		{
			if (g_var.zero == -1)
				ft_putuuu2(va_arg(list, unsigned int), **format);
			else
				ft_putuuu1(va_arg(list, unsigned int), **format);
		}
	}
	if (**format == 's')
		ft_putsss1(va_arg(list, char *));
	if (**format == 'p')
	{
		g_var.point = 1;
		ft_putppp(va_arg(list, unsigned long long));
	}
	if (**format == 'c' || **format == '%')
		ft_putccc(list, **format);
}

void	ft_control2(const char **format, va_list list)
{
	if (**format == 'd' || **format == 'i')
	{
		if (g_var.precesion < 0)
			ft_putddd(va_arg(list, int));
		else
			ft_putddd2(va_arg(list, int), **format);
	}
	if (**format == 'u' || **format == 'x' || **format == 'X')
	{
		if (g_var.precesion < 0)
			ft_putuuu(va_arg(list, unsigned int), **format);
		else
			ft_putuuu2(va_arg(list, unsigned int), **format);
	}
	if (**format == 's')
		ft_putsss1(va_arg(list, char *));
	if (**format == 'p')
	{
		g_var.point = 1;
		ft_putppp(va_arg(list, unsigned long long));
	}
	if (**format == 'c' || **format == '%')
		ft_putccc(list, **format);
}

void	ft_width_funct(const char **format, va_list list)
{
	if (**format == '*')
	{
		g_var.width = va_arg(list, int);
		if (g_var.width < 0)
			g_var.zero = -1;
		g_var.width = (g_var.width < 0) ? -g_var.width : g_var.width;
		(*format)++;
	}
	else
		g_var.width = ft_atoi(format);
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			g_var.precesion = va_arg(list, int);
			(*format)++;
		}
		else
			g_var.precesion = ft_atoi(format);
		ft_control1(format, list);
	}
	else
		ft_control(format, list);
}

void	ft_d(const char **format, va_list list)
{
	if (g_var.precesion < 0)
		ft_putddd(va_arg(list, int));
	else
	{
		if (g_var.zero == -1)
			ft_putddd2(va_arg(list, int), **format);
		else
			ft_putddd1(va_arg(list, int));
	}
}
