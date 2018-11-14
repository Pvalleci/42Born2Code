/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:38:04 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 14:38:05 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		y;
	int		j;
	char	*str;

	y = ft_strlen(s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[y] == ' ' || s[y] == '\n' || s[y] == '\t' || s[y] == '\0'))
		y--;
	if (y < i)
		y = i;
	if (!(str = (char *)malloc(sizeof(char) * (y - i + 1))))
		return (NULL);
	j = i;
	i = 0;
	while (j <= y)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
