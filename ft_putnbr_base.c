/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:02:32 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/18 17:02:34 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int		ft_check(char *base)
{
	int i;
	int j;

	i = 0;
	if (!(base[i] && base[i + 1]))
		return (0);
	while (base[i])
	{
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j] || (base[i] < 32 || base[i] >= 126) ||
				(base[i + j] == '+' || base[i + j] == '-'))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			valbase;
	int			resultat;
	long		nbr2;

	nbr2 = (long)nbr;
	resultat = 0;
	valbase = (int)ft_strlen((const char *)base);
	if (!ft_check(base))
		return ;
	if (nbr == 0)
		return (ft_putchar(base[0]));
	if (nbr2 < 0)
	{
		ft_putchar('-');
		nbr2 = nbr2 * -1;
	}
	if (nbr2 > 9)
	{
		ft_putnbr_base(nbr2 / valbase, base);
	}
	resultat = nbr2 % valbase;
	ft_putchar(base[resultat]);
}
