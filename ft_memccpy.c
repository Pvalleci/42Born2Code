/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:51:36 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 11:51:38 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;
	char	l;
	char	*d;
	char	*s;

	i = 0;
	l = (char)c;
	d = (char *)dest;
	s = (char *)src;
	while (i < (int)n)
	{
		d[i] = s[i];
		i++;
		if (s[i - 1] == l)
			return (&dest[i]);
	}
	return (NULL);
}
