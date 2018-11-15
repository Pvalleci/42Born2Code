/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:30:48 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 15:30:49 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	l;

	str = (char *)s;
	i = ft_strlen(str);
	l = (char)c;
	while (i >= 0)
	{
		if (str[i] == l)
			return (str + i);
		i--;
	}
	return (NULL);
}
