/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:35:02 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/14 17:18:32 by ythomas          ###   ########.fr       */
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
