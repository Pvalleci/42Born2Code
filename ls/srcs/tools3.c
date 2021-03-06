/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 02:01:35 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/14 02:01:43 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_check_space(char **rep_tab, int j, char *option)
{
	if (ft_len_tab(ft_get_intra_rep(rep_tab[j])) == 2 && ft_strchr(option, 'a') == NULL)
		return (-1);
	if (rep_tab[j + 1])
		return (1);
	else
		return (-1);
}

int	ft_filter_recursive(char *option, char **intra_rep)
{
	int	i;

	i = 0;
	if (((ft_strcmp(intra_rep[0] , ".") == 0) 
		&& (ft_strcmp(intra_rep[1] , "..") == 0)) && ft_len_tab(intra_rep) == 2)
		if (ft_strchr(option, 'a') == NULL)
			return (-1);
		return (1);
}

int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}