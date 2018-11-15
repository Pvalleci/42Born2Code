/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:47:46 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 12:47:48 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	l;
	char	*str;

	i = 0;
	l = (char)c;
	str = (char *)s;
	while (n > 0)
	{
		if (str[i] == l)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
