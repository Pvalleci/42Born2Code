/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:24:17 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 15:24:19 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	l;
	char	*str;

	i = 0;
	l = (char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == l)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}
