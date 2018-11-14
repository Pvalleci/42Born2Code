/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:26:27 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/10 15:26:28 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_fill_nbr(char *nbr, int n, int size)
{
	int		i;

	i = 0;
	if (n == 0)
		nbr[i] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		nbr[size--] = ((n % 10) + '0');
		n = n / 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int			size;
	long		nb;
	char		*nbr;

	size = 0;
	nb = n;
	if (nb == 0)
		size++;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	if (!(nbr = (char *)malloc(sizeof(nbr) * (size + 1))))
		return (NULL);
	nbr[size--] = '\0';
	nbr = ft_fill_nbr(nbr, n, size);
	return (nbr);
}
