/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:23:39 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/18 23:23:45 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_affiche_list(t_tetri	*list)
{
	int i;

	while (list != NULL)
	{
		i = 0;
		ft_putchar(list->letter);
		ft_putchar('\n');
		while (i < 4)
		{
			ft_putstr(list->tab[i++]);
			ft_putchar('\n');
		}
		ft_putchar('\n');
		list = list->next;
	}
	return ;
}
