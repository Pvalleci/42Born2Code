/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:55:55 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:55:58 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_fillstr(char *str, int64_t nb, int index)
{
	int		i;
	int64_t	n;

	n = nb;
	i = 0;
	if (n == 0)
		str[i] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (i < index)
		i++;
	i--;
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i] = n % 10 + '0';
	return (str);
}

char			*ft_inttoa(int64_t n)
{
	char	*str;
	int64_t	nb;
	int		i;

	if (n < -9223372036854775807)
		return (str = ft_strdup("-9223372036854775808"));
	nb = n;
	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * (-1);
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_fillstr(str, n, i);
	return (str);
}

char			*ft_utoa(uint64_t nb)
{
	uint64_t	n;
	int			len;
	char		*str;

	len = 0;
	n = nb;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	while (n > 9)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len] = n % 10 + '0';
	return (str);
}
