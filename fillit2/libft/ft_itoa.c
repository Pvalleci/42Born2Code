/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:47:52 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/17 01:47:59 by juaalvar         ###   ########.fr       */
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
