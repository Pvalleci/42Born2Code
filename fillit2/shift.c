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

int		ft_check_void_line(t_tetri *list)
{
	int		i;
	int		decallage;

	i = 0;
	decallage = 0;
	while (list->tab[i])
	{
		if (list->tab[i][0] == '.' && list->tab[i][1] == '.' && list->tab[i][2] == '.')
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

t_tetri	*ft_end_of_line(t_tetri *list)
{
	int i;
	int	j;

	i = 0;
	while (list->tab[i])
	{
		j = 3;
		while (list->tab[i][j] != '#' && j >= 0)
		{
			if (list->tab[i][j] == '.')
				list->tab[i][j] = '\0';
			j--;
		}
		i++;
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
		decallage = ft_check_void_line(list);
		if (decallage != 0)
		{
			ft_correct_void_line(list, decallage);
		}
		ft_end_of_line(list);
		list = list->next;
	}
	return (start);
}