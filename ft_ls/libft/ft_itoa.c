/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:30:17 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:30:22 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_fill_nbr(char *nbr, long n, int size)
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

char		*ft_itoa(int n)
{
	int			size;
	long		nb;
	char		*nbr;

	size = 0;
	nb = (long)n;
	if (nb == 0)
		size++;
	else if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	if (!(nbr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nbr[size] = '\0';
	nbr = ft_fill_nbr(nbr, n, size - 1);
	return (nbr);
}
