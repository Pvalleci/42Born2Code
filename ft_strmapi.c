/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:01:16 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/15 16:48:47 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	char			*s1;

	if (!(s && f))
		return (NULL);
	i = 0;
	s1 = (char *)s;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
