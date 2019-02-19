/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:09:31 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/09 06:21:54 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int				i;
	int				res;
	int				neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == '\t' || nptr[i] == '\f' ||
		nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}
