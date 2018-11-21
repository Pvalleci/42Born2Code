/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 01:39:43 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/20 18:16:51 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int a;
	int b;

	a = nb;
	b = 1;
	while (a > b)
	{
		a = (a + b) / 2;
		b = nb / a;
	}
	if ((a * a) == nb)
		return (a);
	else
		return (0);
}
