/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:16:25 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/27 17:16:38 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char **str)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '+' && **(str + 1) == '-')
		return (0);
	if (**str == '+')
		(*str)++;
	if (**str == '-')
	{
		sign = sign * (-1);
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10 + (**str - '0');
		(*str)++;
	}
	if (nb < 0)
		return ((sign > 0) ? -1 : 0);
	return (sign * nb);
}
