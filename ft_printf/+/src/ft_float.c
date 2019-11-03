/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:54:12 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:54:14 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len_float(t_param *list, int i)
{
	int len;

	if (list->precision == -1)
	{
		len = i + 6 + 1 + list->flag->plus + list->flag->space;
		if (len < list->range)
			len = list->range;
	}
	else if (i + list->precision + 1 + list->flag->plus
		+ list->flag->space < list->range)
		len = list->range;
	else
		len = i + list->precision + 1 + list->flag->plus + list->flag->space;
	return (len);
}

char	*ft_part_float(long double varfloat, t_param *list)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (list->precision == -1)
		len = 6;
	else
		len = list->precision;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (varfloat < 0)
		varfloat = varfloat * (-1);
	while (len > 0)
	{
		varfloat *= 10;
		str[i] = (int)varfloat + '0';
		varfloat = varfloat - (int)varfloat;
		i++;
		len--;
	}
	return (str);
}

char	*fill_buf_two(char *left, char *right, char *buf, int *i)
{
	int j;

	j = ft_strlen(right) - 1;
	while (j >= 0)
	{
		buf[*i] = right[j];
		(*i)--;
		j--;
	}
	buf[(*i)--] = '.';
	j = ft_strlen(left) - 1;
	while (j >= 0)
	{
		buf[*i] = left[j];
		(*i)--;
		j--;
	}
	return (buf);
}

char	*fill_buf(char *left, char *right, t_param *list, int len)
{
	char	*buf;
	int		i;
	char	c;

	c = ' ';
	i = 0;
	if (list->flag->zero == 1)
		c = '0';
	if (!(buf = ft_strnew(len)))
		return (NULL);
	while (i < len)
		buf[i++] = c;
	i = len - 1;
	if (list->flag->minus == 1)
		i = ft_strlen(left) + ft_strlen(right) + list->flag->plus
	+ list->flag->space;
	fill_buf_two(left, right, buf, &i);
	if (list->flag->plus == 1 && left[0] != '-')
		buf[i] = '+';
	else if (list->flag->space == 1)
		buf[i] = ' ';
	return (buf);
}

char	*ft_float(long double varfloat, t_param *list)
{
	int64_t	part;
	int		len_buf;
	char	*part_entiere;
	char	*buf;
	char	*part_float;

	part = (int64_t)varfloat;
	part_entiere = ft_inttoa(part);
	if (part_entiere[0] == '0' && varfloat < 0)
	{
		free(part_entiere);
		part_entiere = ft_strdup("-0");
	}
	len_buf = ft_get_len_float(list, (int)ft_strlen(part_entiere));
	varfloat = varfloat - part;
	part_float = ft_part_float(varfloat, list);
	buf = fill_buf(part_entiere, part_float, list, len_buf);
	free(part_entiere);
	free(part_float);
	return (buf);
}
