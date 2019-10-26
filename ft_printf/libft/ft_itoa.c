/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:10:21 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/15 14:47:12 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_fillstr(char *str, int nb, int index)
{
	int		i;
	long	n;

	n = (long)nb;
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

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = (long)n;
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
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	ft_fillstr(str, n, i);
	return (str);
}
