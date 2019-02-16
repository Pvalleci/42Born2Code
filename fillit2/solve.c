 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:15:10 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/23 11:15:11 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_put(char **map, t_tetri *list, int pos)
{
	int		i;
	int		j;
	int		im;
	int		jm;

	j = 0;
	im = pos % ((int)ft_strlen(map[0])-1);
	while (list->tab[j] && list->tab[j][0] != '\0')
	{
		i = 0;
		jm = pos / ((int)ft_strlen(map[0])-1);
		if (!map[im] && list->tab[j])
			return (0);
		while (list->tab[j][i])
		{
			if (map[im][jm] == '\0' && list->tab[j][i] != '\0')
				return (0);
			if (list->tab[j][i] == '#' && map[im][jm] >= 'A' && map[im][jm] <= 'Z')
				return (0);
			i++;
			jm++;
		}
		j++;
		im++;
	}
	return (1);
}

char	**ft_put_tetri(char **map, t_tetri *list, int pos)
{
	int		i;
	int		j;
	int		im;
	int		jm;

	i = 0;
	im = pos %((int)ft_strlen(map[0]) - 1);
	while (list->tab[i])
	{
		j = 0;
		jm = pos / ((int)ft_strlen(map[0]) - 1);
		while (list->tab[i][j])
		{
			if (list->tab[i][j] == '#')
				map[im][jm] = list->letter;
			jm++;
			j++;
		}
		im++;
		i++;
	}
	list->put = 1;
	return (map);
}

void	ft_aff_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

int		ft_backtrack(char **map, t_tetri *list, int pos)
{
	int 	len;

	len = (int)ft_strlen(map[0]);
	if (list == NULL)
		return (1);
	while (1)
	{
		if (pos >= (len * len))
			return (2);
		if (ft_can_put(map, list, pos) == 1)
		{
			ft_put_tetri(map, list, pos);
			if (ft_backtrack(map, list->next, 0) == 1)
				return (1);
			else
			{
				ft_erase_tetri(map, list);
				list->put = 0;
			}
		}
		pos++;
	}
	return (0);
}

void	ft_solve(t_tetri *list)
{
	char	**map;
	int		len;
	int		pos;

	len = 2;//sqrt (nbr de piece * 4
	pos = 0;
	map = ft_create_map(len);
	while (ft_check_all_put(list) != 1)
	{
		if (ft_backtrack(map, list, 0) == 2)
		{
			map = ft_create_map(len++);
		}
		pos = 0;
	}
	ft_aff_tab(map);
	return ;
}
