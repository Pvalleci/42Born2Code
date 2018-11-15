/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:37:21 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 12:37:23 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*strdest;
	char	*strsrc;

	strdest = (char *)dest;
	strsrc = (char *)src;
	if (strsrc < strdest && strdest < strsrc + len)
	{
		strsrc = strsrc + len;
		strdest = strdest + len;
		while (len != 0)
		{
			*--strdest = *--strsrc;
			len--;
		}
	}
	else
		while (len != 0)
		{
			*strdest++ = *strsrc++;
			len--;
		}
	return (dest);
}
