/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:22:58 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/14 13:46:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	i;
	size_t	y;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	y = lendst;
	if (size > lendst + 1)
	{
		while (src[i] && y < size - 1)
		{
			dst[y] = src[i];
			i++;
			y++;
		}
		dst[y] = '\0';
	}
	if (size >= lendst)
		return (lendst + lensrc);
	return (lensrc + size);
}
