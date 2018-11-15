/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:51:23 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 11:51:24 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;
	char	*s1;

	s1 = (char*)s;
	if (!(s && f))
		return (0);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = f(s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
