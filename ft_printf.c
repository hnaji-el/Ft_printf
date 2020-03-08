/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:42:44 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/29 23:03:40 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list;

	g_var.ret = 0;
	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_format(&format, list);
			format++;
			ft_init_struct();
		}
		while (*format != '\0' && *format != '%')
		{
			ft_put_char(*format);
			format++;
		}
	}
	va_end(list);
	return (g_var.ret);
}
