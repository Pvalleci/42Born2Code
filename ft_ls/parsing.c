/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:28:12 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 16:28:14 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_get_option(int ac, char **av)
{
	int 	i;
	char	*option;

	i = 1;
	if (!(option = ft_strnew(0)))
		return (NULL);
	while (i < ac && av[i][0] == '-')
	{
		if (!(option = ft_strjoin(option, av[i] + 1)))
			return (NULL);
		i++;
	}
	return (option);
}

char	**ft_get_path(int ac, char **av)
{
	int		i;
	int		nb_opt;
	char	**path;

	nb_opt = 1;
	path = NULL;
	while (nb_opt < ac && av[nb_opt][0] == '-')
		nb_opt++;
	if (nb_opt >= ac)
		return (NULL);
	if (!(path = (char **)malloc(sizeof(char *) * (ac - nb_opt) + 1)))
		return (NULL);
	i = 0;
	while (nb_opt < ac)
	{
		if (!(path[i] = ft_strdup(av[nb_opt])))
			return (NULL);
		i++;
		nb_opt++;
	}
	if (i != 0)
		path[i] = NULL;
	return (path);
}
