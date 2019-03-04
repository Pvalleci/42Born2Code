/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:31:54 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:31:57 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*dest2;
	char	*src2;
	int		n2;
	int		i;

	i = 0;
	n2 = (int)n;
	src2 = (char*)src;
	dest2 = (char*)dest;
	while (i < n2)
	{
		dest2[i] = src2[i];
		if (src2[i] == (char)c)
			return (dest2 + i + 1);
		i++;
	}
	return (NULL);
}
