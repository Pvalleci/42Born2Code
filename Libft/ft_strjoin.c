/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:52:27 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 12:52:28 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(str) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		str[j] = (char)s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = (char)s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
