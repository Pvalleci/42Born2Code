/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:00:02 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/18 23:00:05 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_buf(char *buf)
{
	int		i;

	i = 0;
	if (ft_strlen(buf) != 4 && buf[0] != '\0')
		return (0);
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_tetri(char **tab)
{
	int		i;
	int		j;
	int		nb_co;

	i = 0;
	nb_co = 0;
	while (tab[i])
	{	
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				if ((j - 1) >= 0 && tab[i][j - 1] == '#')
					nb_co++;
				if ((j + 1) < 4 && tab[i][j + 1] == '#')
					nb_co++;
				if ((i - 1) >= 0 && tab[i - 1][j] == '#')
					nb_co++;
				if ((i + 1) < 4 && tab[i + 1][j] == '#')
					nb_co++;
			}
			j++;
		}
		i++;
	}
	if (nb_co != 6 && nb_co != 8)
		return (0);
	return (1);
}

int		ft_check_list(t_tetri *list)
{
	while (list != NULL)
	{
		if (ft_check_tetri(list->tab) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

