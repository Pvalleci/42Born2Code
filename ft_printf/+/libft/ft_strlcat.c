/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:39:36 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:39:39 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dest_len;
	size_t src_len;

	i = 0;
	dest_len = ft_strlen(dst);
	j = dest_len;
	src_len = ft_strlen((char *)src);
	if (size > dest_len + 1)
	{
		while (src[i] && j < (size - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (size >= dest_len)
		return (dest_len + src_len);
	return (src_len + size);
}
