/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:34:03 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/23 11:34:05 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return ;
}

void	ft_free_list(t_tetri *list)
{
	t_tetri		*tmp;
	int			i;

	while (list != NULL)
	{
		tmp = list;
		i = 0;
		while (i < 5)
		{
			free(list->tab[i]);
			i++;
		}
		list = list->next;
		free(tmp);
	}
}

char	**ft_erase_tetri(char **map, t_tetri *list)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
