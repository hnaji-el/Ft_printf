/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:57:13 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/28 11:28:55 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_zero(const char **format, va_list list)
{
	if (g_var.width >= 0)
		g_var.zero = 1;
	else
	{
		g_var.zero = -1;
		g_var.width = -g_var.width;
	}
	ft_control(format, list);
	return (0);
}

int		ft_flagz_prec(const char **format, va_list list)
{
	if (g_var.precesion < 0)
		ft_flag_zero(format, list);
	else
	{
		if (g_var.width >= 0)
		{
			g_var.zero = 1;
			ft_control1(format, list);
		}
		else
		{
			g_var.zero = -1;
			g_var.width = -g_var.width;
			ft_control2(format, list);
		}
	}
	return (0);
}

int		ft_percent(const char **format, va_list list)
{
	g_var.zero = -1;
	while (**format == '0' || **format == '-')
		(*format)++;
	if (**format == '*')
	{
		g_var.width = va_arg(list, int);
		g_var.width = (g_var.width < 0) ? -g_var.width : g_var.width;
		(*format)++;
	}
	else
		g_var.width = ft_atoi(format);
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
			(*format)++;
		else
			ft_atoi(format);
	}
	ft_putccc(list, '%');
	return (0);
}

int		ft_zero_func(const char **format, va_list list)
{
	while (**format == '0')
		(*format)++;
	if (**format == '-')
		return (ft_percent(format, list));
	if (**format == '*')
	{
		g_var.width = va_arg(list, int);
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
		return (ft_flagz_prec(format, list));
	}
	else
		return (ft_flag_zero(format, list));
}
