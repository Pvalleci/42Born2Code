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

#include "libft.h"

static int		ft_nb_word(char const *s, char c)
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

static void		*ft_malloc_tab(const char *str, char **tab, char c)
{
	int i;
	int j;
	int word;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		word = 0;
		while (str[i + word] != c && str[i + word] != '\0')
			word++;
		if (!(tab[j] = (char *)malloc(sizeof(**tab) * word + 1)))
			return (NULL);
		j++;
		i = i + word;
	}
	j++;
	if (!(tab[j] = (char *)malloc(sizeof(**tab) * 1)))
		return (NULL);
	return (0);
}

static void		ft_input_tab(const char *str, char **tab, char c)
{
	int i;
	int x;
	int word;

	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		word = 0;
		while (str[i + word] != c && str[i + word] != '\0')
		{
			tab[x][word] = str[i + word];
			word++;
		}
		if (word != 0)
			tab[x++][word] = '\0';
		i = i + word;
	}
	tab[x] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (!(s && c))
		return (NULL);
	if (s[0] == '\0')
		return (0);
	if (!(tab = (char **)malloc(sizeof(*tab) * ft_nb_word(s, c) + 1)))
		return (NULL);
	ft_malloc_tab(s, tab, c);
	ft_input_tab(s, tab, c);
	return (tab);
}
