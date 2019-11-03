/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:56:03 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:56:05 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_number(uint64_t nb, uint64_t val_base)
{
	int		len;

	len = 0;
	while (nb > val_base - 1)
	{
		nb = nb / val_base;
		len++;
	}
	len++;
	return (len);
}

char	*ft_diu_flag_no_minus(char *str, char *b, int range, t_param *list)
{
	int i;

	i = ft_strlen(str) - 1;
	range--;
	while (i >= 0)
	{
		b[range] = str[i];
		i--;
		range--;
	}
	if (list->flag->plus == 1 && str[0] != '-')
		b[range] = '+';
	return (b);
}

char	*ft_bchar(char *tmp, int len, char c)
{
	len--;
	while (len >= 0)
		tmp[len--] = c;
	return (tmp);
}

int		ft_check_format(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_skip_param(char *f)
{
	int i;

	i = 1;
	while (f[i] != '\0' && f[i] != 'd' && f[i] != 'i' && f[i] != 'o'
		&& f[i] != 'u' && f[i] != 'x' && f[i] != 'X' && f[i] != 'c'
		&& f[i] != 's' && f[i] != 'p' && f[i] != 'f' && f[i] != '%')
		i++;
	return (i);
}
