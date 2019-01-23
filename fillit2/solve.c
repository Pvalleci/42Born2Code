/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:18:34 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/21 14:18:36 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_all_put(t_tetri *list)
{
	while (list != NULL)
	{
		if (list->put == 1)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

void	free_list(t_tetri *list)
{
	t_tetri	*tmp;

	tmp = list;
	while (list != NULL)
	{
		while (i < 5)
			free(list->tab[i++]);
		list = list->next;
		free(tmp);
	}
}

char	**ft_create_map(int len)
{
	char	**map;
	int 	i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * len + 1);
	while (i < 5)
	{
		map[i] = ft_strnew(len);
		i++;
	}
	map[i] = 0;
	return (map);
}

char	**ft_copy_to_new_map(char **new_map, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		new_map[i][j] = '.';
		i++;
	}
	new_map[i][j] = '.';
	while (j > 0)
		new_map[i][j--] = '.';
	return (new_map);
}


char	**ft_resize_map(char **map)
{
	int		len;
	int		i;
	char	**new_map;

	len = 0;
	i = 0;
	while (map[0][i])
		i++;
	len = i;
	new_map = ft_create_map(len);
	ft_copy_to_new_map(new_map, map);
	ft_free_map(map);
	return (new_map);
}
