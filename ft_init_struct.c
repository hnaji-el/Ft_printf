/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:16:58 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/01/30 11:45:27 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(void)
{
	g_var.width = 0;
	g_var.precesion = 0;
	g_var.precesion1 = 0;
	g_var.len1 = 0;
	g_var.sign = 0;
	g_var.zero = 0;
	g_var.n = 0;
	g_var.num = 0;
	g_var.point = 0;
}
