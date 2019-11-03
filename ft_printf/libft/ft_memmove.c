/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:34:46 by pvalleci          #+#    #+#             */
/*   Updated: 2019/11/03 14:34:48 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strdst;
	char	*strsrc;

	strdst = (char*)dst;
	strsrc = (char*)src;
	if (strsrc < strdst && strdst < strsrc + len)
	{
		strsrc = strsrc + len;
		strdst = strdst + len;
		while (len != 0)
		{
			*--strdst = *--strsrc;
			len--;
		}
	}
	else
		while (len != 0)
		{
			*strdst++ = *strsrc++;
			len--;
		}
	return (dst);
}
