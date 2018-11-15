/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 01:58:46 by pvalleci          #+#    #+#             */
/*   Updated: 2018/09/13 01:58:48 by pvalleci         ###   ########.fr       */
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
	dest_len = ft_strlen((const char *)dst);
	j = dest_len;
	src_len = ft_strlen(src);
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
