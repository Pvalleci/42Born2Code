/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:09:48 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/23 10:09:50 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_shift(t_tetri *list)
{
	int		decallage;
	int		ref;
	int		j;
	int		i;

	ref = 4;
	j = 0;
	while (list->tab[j])
	{
		decallage = 0;
		i = 0;
		while (list->tab[j][i] == '.')
		{
			i++;
			decallage++;
		}
		j++;
		if (decallage < ref)
			ref = decallage;
	}
	return (ref);
}

t_tetri	*ft_correct_tetri(t_tetri *list, int decallage)
{
	int	j;
	int i;

	j = 0;
	while (list->tab[j])
	{
		i = 0;
		while (list->tab[j][i])
		{
			if (list->tab[j][i] == '#')
			{
				list->tab[j][i - decallage] = '#';
				list->tab[j][i] = '.';
			}
			i++;
		}
		j++;
	}
	return (list);
}

t_tetri	*ft_correct_shift(t_tetri *list)
{
	int			decallage;
	t_tetri 	*start;
	int			j;
	
	start = list;
	while (list != NULL)
	{
		j = 0;
		decallage = ft_check_shift(list);
		if (decallage != 0)
			ft_correct_tetri(list, decallage);
		list = list->next;
	}
	return (start);
}