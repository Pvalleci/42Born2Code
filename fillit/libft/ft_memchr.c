/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 07:01:36 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/11 07:01:37 by juaalvar         ###   ########.fr       */
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
