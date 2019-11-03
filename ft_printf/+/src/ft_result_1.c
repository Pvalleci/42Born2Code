/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:55:32 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:55:35 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_result_p(t_param *list)
{
	char	*str;

	str = ft_pointeur(list);
	return (str);
}

char		*ft_get_result_xx(t_param *list)
{
	char *str;
	char c;

	c = ' ';
	if (list->flag->zero == 1)
		c = '0';
	if (list->variable == 0)
		list->flag->ash = 0;
	if (list->conversion == 'x')
		str = ft_hexa(list->variable, "0123456789abcdef", 16);
	else
		str = ft_hexa(list->variable, "0123456789ABCDEF", 16);
	if (list->precision > (int)ft_strlen(str)
		|| (list->precision == 0 && list->variable == 0))
		str = ft_precision(str, list);
	str = ft_range_xxo(str, list, 2, c);
	return (str);
}

char		*ft_get_result_f(t_param *list)
{
	char *str;

	if (list->varfloat < 0)
	{
		list->flag->plus = 0;
		list->flag->space = 0;
	}
	if (list->modifier == 5)
		str = ft_float(list->varfloat, list);
	else if (list->modifier == 3)
		str = ft_float((double)list->varfloat, list);
	else
		str = ft_float((float)list->varfloat, list);
	return (str);
}

char		*ft_get_result_o(t_param *list)
{
	char *str;
	char c;

	c = ' ';
	if (list->flag->zero == 1)
		c = '0';
	str = ft_hexa(list->variable, "01234567", 8);
	if (list->precision > (int)ft_strlen(str)
		|| (list->precision == 0 && list->variable == 0))
		str = ft_precision(str, list);
	str = ft_range_xxo(str, list, 1, c);
	return (str);
}

t_param		*ft_get_result(t_param *list)
{
	t_param		*depart;

	depart = list;
	while (list != NULL)
	{
		if (list->conversion == 's')
			list->result = ft_get_result_s(list);
		else if (list->conversion == 'c' || list->conversion == '%')
			list->result = ft_get_result_c(list);
		else if (list->conversion == 'd' || list->conversion == 'i')
			list->result = ft_get_result_di(list);
		else if (list->conversion == 'u')
			list->result = ft_get_result_u(list);
		else if (list->conversion == 'p')
			list->result = ft_get_result_p(list);
		else if (list->conversion == 'x' || list->conversion == 'X')
			list->result = ft_get_result_xx(list);
		else if (list->conversion == 'f')
			list->result = ft_get_result_f(list);
		else if (list->conversion == 'o')
			list->result = ft_get_result_o(list);
		list = list->next;
	}
	return (depart);
}
