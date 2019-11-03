/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:55:00 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:55:03 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t		ft_get_var_csp(t_param *list, va_list ap)
{
	char c;

	c = '%';
	if (list->conversion == '%')
		return (list->variable = (uint64_t)c);
	if (list->conversion == 'c')
		return (list->variable = (uint64_t)(va_arg(ap, int)));
	if (list->conversion == 's')
		return (list->variable = (uint64_t)(va_arg(ap, char *)));
	if (list->conversion == 'p')
		return (list->variable = (uint64_t)(va_arg(ap, void *)));
	return (0);
}

uint64_t		ft_get_var_di(t_param *list, va_list ap)
{
	if (list->modifier == 4)
		return (list->variable = (uint64_t)(va_arg(ap, long long int)));
	if (list->modifier == 3)
		return (list->variable = (uint64_t)(va_arg(ap, long int)));
	if (list->modifier <= 2 || list->modifier == 5)
		return (list->variable = (uint64_t)(va_arg(ap, int)));
	return (0);
}

uint64_t		ft_get_var_uoxx(t_param *l, va_list ap)
{
	if (l->modifier == 4)
		return (l->variable = (uint64_t)(va_arg(ap, unsigned long long int)));
	if (l->modifier == 3)
		return (l->variable = (uint64_t)(va_arg(ap, unsigned long int)));
	if (l->modifier <= 2 || l->modifier == 5)
		return (l->variable = (uint64_t)(va_arg(ap, unsigned int)));
	return (0);
}

uint64_t		ft_get_var_float(t_param *list, va_list ap)
{
	if (list->modifier == 5)
		return (list->varfloat = (va_arg(ap, long double)));
	else
		return (list->varfloat = (long double)(va_arg(ap, double)));
}
