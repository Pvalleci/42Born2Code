/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:04:38 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 13:25:17 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*strs;
	char			*strd;
	unsigned int	i;
	char			lettre;

	strs = (char*)src;
	strd = (char*)dst;
	lettre = (char)c;
	i = 0;
	while (i < n)
	{
		if (strs[i] == lettre)
		{
			strd[i] = strs[i];
			return (dst + i + 1);
		}
		strd[i] = strs[i];
		i++;
	}
	return (0);
}
