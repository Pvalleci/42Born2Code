/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:29:39 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/11 06:29:40 by juaalvar         ###   ########.fr       */
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
