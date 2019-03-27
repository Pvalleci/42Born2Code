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

int			ft_s_is_dir(char *name)
{
	struct stat stats;

	if (stat(name, &stats) < 0)
		return (0);
	if (S_ISDIR(stats.st_mode) == 1)
		return (1);
	return (0);
}

int			ft_check_is_rep(char *name)
{
	DIR				*dir;
	struct dirent	*rep;

	if (!(dir = opendir(name)))
		return (0);
	rep = readdir(dir);
	closedir(dir);
	if (ft_s_is_dir(name) == 1)
		return (1);
	return (0);
}

void		ft_ls(char *name, char *option, int nb_path)
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
	ft_sort_tab(name, option, tab);
	ft_display(name, tab, option, nb_path);
	if (!tab || !tab[0])
		return ;
	if (option != NULL && ft_strchr(option, 'R') != NULL)
		ft_ls_recusive(tab, name, option, nb_path);
	ft_free_list(start);
	ft_free_tab(tab);
}

int		main(int ac, char **av)
{
	int			i;
	int 		nb_path;
	char		*option;
	char		**path;

	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	nb_path = ft_len_tab(path);
	path = ft_verif_folders(path);
	i = 0;
	ft_sort_tab(NULL, option, path);
	while (path && path[i] != NULL)
	{
		ft_ls(path[i], option, nb_path);
		i++;
	}
	if (!path)
		ft_ls(".", option, nb_path);
	if (path)
		ft_free_tab(path);
	free(option);
	// while (1)
	// 	;
	return (1);
}
