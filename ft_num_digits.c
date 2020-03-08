/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:17:25 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/27 17:17:32 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numb_dd(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + ft_numb_dd(nb / 10));
}

int		ft_numb_ux(unsigned int nb, char c)
{
	int		i;
	int		b;

	i = 0;
	b = 16;
	if (c == 'u')
		b = 10;
	while (nb != 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int		ft_numb_pp(unsigned long long nb)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 2);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
