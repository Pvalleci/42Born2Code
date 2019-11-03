/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:55:10 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:55:13 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cutstr(char *str, t_param *list)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strnew(list->precision)))
		return (NULL);
	i = 0;
	while (i < list->precision)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	if (list->variable == 0)
		free(str);
	return (tmp);
}

char	*ft_fill_preci_uid(char *str, t_param *list)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str[0] == '-')
	{
		if (!(tmp = ft_strnew(list->precision + 1)))
			return (NULL);
		tmp[0] = '-';
		i++;
		while (i < list->precision + 1)
			tmp[i++] = '0';
	}
	else
	{
		if (!(tmp = ft_strnew(list->precision)))
			return (NULL);
		while (i < list->precision)
			tmp[i++] = '0';
	}
	return (tmp);
}

char	*ft_cut_int(char *str, t_param *list)
{
	char	*tmp;
	int		i;
	int		len;

	len = (int)ft_strlen(str) - 1;
	tmp = ft_fill_preci_uid(str, list);
	i = ft_strlen(tmp);
	i--;
	while (len >= 0 && str[len] != '-')
	{
		tmp[i] = str[len];
		i--;
		len--;
	}
	free(str);
	return (tmp);
}

char	*ft_cut_base(char *str, t_param *list)
{
	char	*tmp;
	int		len;
	int		i;

	if (!(tmp = ft_strnew(list->precision)))
		return (NULL);
	len = (int)ft_strlen(str) - 1;
	i = list->precision - 1;
	while (len >= 0)
	{
		tmp[i] = str[len];
		i--;
		len--;
	}
	while (i >= 0)
		tmp[i--] = '0';
	free(str);
	return (tmp);
}

char	*ft_precision(char *str, t_param *list)
{
	if (list->conversion == 's')
		return (ft_cutstr(str, list));
	else if (list->conversion == 'd' || list->conversion == 'i'
		|| list->conversion == 'u')
		return (ft_cut_int(str, list));
	else if (list->conversion == 'x' || list->conversion == 'X'
		|| list->conversion == 'o')
		return (ft_cut_base(str, list));
	return (NULL);
}
