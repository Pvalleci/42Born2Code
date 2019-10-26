/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodimtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:33:15 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/17 18:06:58 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		**ft_twodimtab(int largeur, int hauteur)
{
	int	**tab;
	int i;

	if (!hauteur || !largeur)
		return (NULL);
	if (!(tab = (int**)malloc(sizeof(int*) * hauteur)))
		return (NULL);
	i = 0;
	while (i < hauteur)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * largeur)))
			return (NULL);
		i++;
	}
	return (tab);
}
