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


int		ft_check_tetriminos(char *str)//verf des tetri
{
	int		i;
	int		nb_co;
	int		len;
	int		nb_hash;

	len = ft_strlen(str);
	i = 0;
	nb_hash = 0;
	if (len % 4 != 0 || len > 416)//bon nmr de line t moins de 27 tetri
		return (-1);
	nb_co = 0;
	while (str[i])//verfi du nmr de # et de leur connections
	{
		if (str[i] == '#')
			nb_hash++;
		//peut placer la suite ds une fonction facilemt
		if (str[i] == '#' && (i - 1) >= 0 && str[i - 1] == '#')
			nb_co++;
		if (str[i] == '#' && (i + 1) <= len && str[i + 1] == '#')
			nb_co++;
		if (str[i] == '#' && (i + 4) <= len && str[i + 4] == '#')
			nb_co++;
		if (str[i] == '#' && (i - 4) >= 0 && str[i - 4] == '#')
			nb_co++;
		if ((i + 1) % 16 == 0 && i != 0)
		{
			if ((nb_co != 6 && nb_co != 8) || nb_hash != 4)
			{
				free(str);
				return (-1);
			}
			nb_co = 0;
			nb_hash = 0;
		}
		i++;
	}
	return (0);
}
