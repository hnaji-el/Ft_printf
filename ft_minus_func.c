/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:51:43 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/28 12:42:17 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_zero1(const char **format, va_list list)
{
	g_var.zero = -1;
	if (g_var.width < 0)
		g_var.width = -g_var.width;
	ft_control(format, list);
	return (0);
}

int		ft_flagz_prec1(const char **format, va_list list)
{
	g_var.zero = -1;
	if (g_var.width < 0)
		g_var.width = -g_var.width;
	ft_control2(format, list);
	return (0);
}

int		ft_minus_func(const char **format, va_list list)
{
	while (**format == '-')
		(*format)++;
	if (**format == '0')
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
		return (ft_flagz_prec1(format, list));
	}
	else
		return (ft_flag_zero1(format, list));
}
