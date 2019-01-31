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
	int	i;
	int len;

	i = 0;
	len = (int)ft_strlen(map[0]);
	while (list->tab[i / 4][i % 4] == '.')
		i++;
	printf("MAP:\n");
	while (map[pos / len] && list->tab[i / 4])
	{
		if (map[pos / len][pos % len] == '#' && list->tab[i / 4][i % 4] == '#')
			return (0);
		while ((i % 4) != 0 && list->tab[i / 4][i % 4] == '.'
			&& list->tab[(i + 1) / 4][(i + 1) % 4] != '#')
			i++;
		i++;
		pos++;
	}
	return (1);
}

void	ft_put_tetri(char **map, t_tetri *list, int pos)
{
	// int		len;
	// int 	i;
	// int 	j;

	// i = 0;
	// j = 0;
	// len = ft_strlen(map[0]);
	// while (pas[pos / len][pos % len] && list->tab[j])
	// {
	// 	if(list->tab[j][i] == '.' && )
	// }
	;
}

char	**ft_backtrack(char **map, t_tetri *list, int len)
{
	int		pos;

	pos = 0;
	while (list != NULL && pos < (len * len))
	{
		if (list->put == 1)
			list = list->next;
		if (list == NULL)
			break ;
		if (ft_can_put(map, list, pos) == 1)
		{
			printf("can put ?\n");
			ft_put_tetri(map, list , pos);
			list->put = 1;
			ft_backtrack(map, list->next, len);
		}
		ft_erase_tetri(map, list);
		list->put = 0;
		pos++;
	}
	return (map);
}

void	ft_solve(t_tetri *list)
{
	char	**map;
	int		len;

	len = 1;
	map = ft_create_map(len);
	while (ft_check_all_put(list) == 0)
	{
		map = ft_resize_map(map);
		len++;
		ft_backtrack(map, list, len);
	}
	//ft_affiche_resultat(map);
}
