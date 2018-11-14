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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (dest_len);
	if (size < dest_len)
	{
		while (i < (size - dest_len - 1))
		{
			dest[i + dest_len] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	if (size >= dest_len)
		return (dest_len + src_len);
	return (src_len + size);
}
