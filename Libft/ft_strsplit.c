/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:46 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 14:45:48 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_nb_word(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if ((s[i] == c || i == 0) && (s[i + 1] != c && s[i + 1] != '\0'))
			nb++;
		i++;
	}
	return (nb);
}

char	**ft_fill_str(char **str, const char *s, char c)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	while (s[i] && j < ft_nb_word(s, c))
	{
		l = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[j][l] = (char)s[i];
			l++;
			i++;
		}
		str[j][l] = '\0';
		j++;
	}
	str[j] = "\0";
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		word;

	j = 0;
	if (!(str = (char **)malloc(sizeof(*str) * (ft_nb_word(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			word++;
			i++;
		}
		if (!(str[j] = (char *)malloc(sizeof(*str) * (word + 1))))
			return (NULL);
		j++;
	}
	str = ft_fill_str(str, s, c);
	return (str);
}
