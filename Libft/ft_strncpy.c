/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:54:13 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 13:54:14 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	if (src[i] == '\0')
		dest[i] = src[i];
	return (dest);
}
