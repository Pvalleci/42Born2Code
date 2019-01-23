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

	i = pos / ft_strlen(map[0]);
	j = pos % ft_strlen(map[0]);
	
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
			ft_put_tetri(map, tetri, pos);
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
		ft_resize_map(map);
		len++;
		ft_backtrack(map, list, len);
	}
	ft_affiche_resultat(map);
}
