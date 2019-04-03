/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:33:57 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:33:59 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	int		n2;
	int		i;

	i = 0;
	dest2 = (char*)dest;
	src2 = (char*)src;
	n2 = (int)n;
	while (i < n2)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
