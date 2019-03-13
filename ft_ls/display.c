/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:19:06 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 19:19:09 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_l(char **tab)
{
	
}

void	ft_display(char *name, char **tab, char *option)
{
	if (ft_strchr(option, 'l'))
		ft_print_l(tab);
	else
		ft_print_table(tab);
}
