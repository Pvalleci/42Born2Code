/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:28:02 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 16:28:04 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_check_is_rep(char *name)
{
	DIR				*dir;
	struct dirent	*rep;

	if (!(dir = opendir(name)))
	{
		return (0);
	}
	rep = readdir(dir);
	if (rep->d_type == 4)
		return (1);
	return (0);
}



void		ft_ls(char *name, char *option)
{
	t_list_ls	*list_ls;
	t_list_ls	*start;
	char		**tab;

	list_ls = NULL;
	list_ls = ft_create_list(name);
	if (list_ls == NULL)
		return ;
	start = list_ls;
	tab = ft_to_tab(list_ls, option);
	if (!tab)
		return ;
	ft_sort_tab(name, option, tab);
	ft_print_table(tab);
	if (ft_strchr(option, 'R') != NULL)
	{
		ft_ls_recusive(list_ls, name, option);
	}
	ft_free_list(start);
	ft_free_tab(tab);
}

int		main(int ac, char **av)
{
	int			i;
	char		*option;
	char		**path;

	option = ft_get_option(ac, av);
	path = ft_get_path(ac, av);
	//pars option;
	//pars path;
	i = 0;
	while (path && path[i] != NULL)
	{
		ft_ls(path[i], option);
		i++;
	}
	if (!path)
		ft_ls(".", option);
	//else
	//	free(path)
	free(option);
	return (1);
}
