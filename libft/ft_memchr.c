/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:33:30 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:33:33 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s2;
	int		n2;
	int		i;

	i = 0;
	n2 = (int)n;
	s2 = (char*)s;
	while (i < n2)
	{
		if (s2[i] == (char)c)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
