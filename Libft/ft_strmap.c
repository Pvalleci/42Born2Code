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

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		str[i] = (char)f(s[i]);
		i++;
	}
	str[i] = (char)f(s[i]);
	return (str);
}
