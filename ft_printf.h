/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:55:35 by hnaji-el          #+#    #+#             */
/*   Updated: 2020/02/24 11:40:17 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_liste
{
	int					width;
	int					precesion;
	int					precesion1;
	int					len1;
	int					sign;
	int					zero;
	int					ret;
	int					n;
	unsigned int		num;
	int					point;
}					t_liste;

t_liste				g_var;

int					ft_printf(const char *format, ...);
void				ft_format(const char **format, va_list list);
void				ft_put_char(char c);
void				ft_put_str(char *str);
void				ft_put_nbr(int nb);
void				ft_put_uxx(unsigned int nb, char c);
void				ft_put_add(unsigned long long nb);
int					ft_atoi(const char **str);
void				ft_width_funct(const char **format, va_list list);
void				ft_init_struct(void);
int					ft_numb_dd(int nb);
int					ft_numb_ux(unsigned int nb, char c);
int					ft_numb_pp(unsigned long long nb);
size_t				ft_strlen(char *s);
void				ft_control(const char **format, va_list list);
void				ft_control1(const char **format, va_list list);
void				ft_control2(const char **format, va_list list);
void				ft_putddd(int nb);
void				ft_putccc(va_list list, char c);
void				ft_putsss(char *ptr);
void				ft_putuuu(unsigned int nb, char c);
void				ft_putppp(unsigned long long nb);
void				ft_putddd1(int nb);
void				ft_putuuu1(unsigned int nb, char c);
void				ft_putsss1(char *ptr);
void				ft_putddd2(int nb, char c);
void				ft_putuuu2(unsigned int nb, char c);
void				ft_put_zero(int len);
void				ft_put_zero_space(int len);
void				ft_precesion_max(char *ptr);
void				ft_width_max(char *ptr, int len);
void				ft_putchar_minus(void);
int					ft_zero_func(const char **format, va_list list);
int					ft_flag_zero(const char **format, va_list list);
int					ft_percent(const char **format, va_list list);
int					ft_flagz_prec(const char **format, va_list list);
void				ft_put_zero2(int len, char c);
void				ft_put_zero_space2(int len, char c);
void				ft_put_nb(char c);
void				ft_zero_prec_zero(unsigned int nb, char c);
int					ft_minus_func(const char **format, va_list list);
int					ft_flag_zero1(const char **format, va_list list);
int					ft_flagz_prec1(const char **format, va_list list);
void				ft_d(const char **format, va_list list);

#endif
