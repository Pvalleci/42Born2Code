/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:35:34 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 10:35:36 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*tab;
	size_t	i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
