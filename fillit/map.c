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

int		ft_nb_tetri(t_tetri *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int		ft_sqrt_fillit(int len)
{
	int		i;

	i = 0;
	while ((i * i) < len)
	{
		i++;
	}
	return (i);
}

char	**ft_create_map(int len)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (i < len)
	{
		j = 0;
		map[i] = ft_strnew(len);
		while (j < len)
			map[i][j++] = '.';
		i++;
	}
	map[i] = 0;
	return (map);
}
