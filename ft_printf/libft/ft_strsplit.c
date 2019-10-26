/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:52:01 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/14 18:35:24 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		cw(const char *s, char c)
{
	int i;
	int y;

	if (!s || !c)
		return (0);
	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			y++;
		else if (s[i] != c && s[i - 1] == c)
			y++;
		i++;
	}
	return (y);
}

static int		df(const char *s, char c)
{
	int i;

	if (!s || !c)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		y;
	int		z;

	if (!(str = (char**)malloc(sizeof(char*) * (cw(s, c) + 1))) || !s || !c)
		return (NULL);
	i = 0;
	y = 0;
	z = 0;
	while (z < cw(s, c))
	{
		if (!(str[z] = (char*)malloc(sizeof(char) * (df((s + i), c) + 1))))
			return (NULL);
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			str[z][y++] = s[i++];
		str[z][y] = '\0';
		y = 0;
		z++;
		i++;
	}
	str[z] = 0;
	return (str);
}
