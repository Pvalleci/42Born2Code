/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:27:45 by pvalleci          #+#    #+#             */
/*   Updated: 2019/02/19 15:27:48 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_void_line(t_tetri *list)
{
	int		i;
	int		decallage;

	i = 0;
	decallage = 0;
	while (list->tab[i])
	{
		if (list->tab[i][0] == '.' && list->tab[i][1] == '.'
			&& list->tab[i][2] == '.')
			decallage++;
		else
			break ;
		i++;
	}
	return (decallage);
}

t_tetri		*ft_correct_void_line(t_tetri *list, int decallage)
{
	int		i;
	int		j;

	i = 0;
	while (list->tab[i])
	{
		j = 0;
		while (list->tab[i][j])
		{
			if (list->tab[i][j] == '#')
			{
				list->tab[i - decallage][j] = '#';
				list->tab[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (list);
}
