/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:31:36 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/29 22:27:50 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char **format, va_list list)
{
	(*format)++;
	if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x'
	|| **format == 'X' || **format == 99 || **format == 's' || **format == 'p'
	|| **format == '%')
		ft_control(format, list);
	if ((**format >= '1' && **format <= '9') || **format == '.' ||
	**format == '*')
		ft_width_funct(format, list);
	if (**format == '0')
		ft_zero_func(format, list);
	if (**format == '-')
		ft_minus_func(format, list);
}
