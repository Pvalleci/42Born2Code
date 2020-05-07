/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 01:59:56 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/14 18:00:29 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_clean_path(char *path, char *rep)
{
	char	*tmp;
	char	*tmp2;

	if (ft_only_char(path, '/') == 1)
	{
		if (!(tmp = ft_strdup(path)))
			return (NULL);
	}
	else
		if (!(tmp = ft_strjoin(path , "/")))
			return (NULL);
	if (!(tmp2 = ft_strjoin(tmp, rep)))
		return (NULL);
	ft_strdel(&tmp);
	return (tmp2);
}

char		**ft_create_path(void)
{
	char **path;

	if (!(path = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	if (!(path[0] = ft_strdup(".")))
		return (NULL);
	path[1] = NULL;
	return (path);
}

char		**ft_create_tmp(char *path, char *intra_rep)
{
	char **tmp_recur;

	if (!(tmp_recur = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tmp_recur[0] = ft_clean_path(path, intra_rep);
	tmp_recur[1] = NULL;
	return (tmp_recur);
}

int			ft_check_intra_rep(char **intra_rep, char *option)
{
	if (intra_rep == NULL)
		return (-1);
	if ((ft_filter_recursive(option, intra_rep) == -1))
		ft_free_tab(intra_rep);
	return (-1);
}

void		ft_tmp_ls(char *path, char *intra_rep, int i, char *option)
{
	char **tmp_recur;

			if ((tmp_recur = ft_create_tmp(path, intra_rep)))
				write(1, "\n", 1);
			ft_ls(tmp_recur, option, i);
			ft_free_tab(tmp_recur);
}

int			ft_recursive_ls(char *path, char *option, int i)
{
	char	*tmp;
	char	**intra_rep;
	int 	j;
	struct stat buf;

	j = 0;
	if (!(intra_rep = ft_get_intra_rep(path)))
		if (ft_check_intra_rep(intra_rep, option) == -1)
			return (-1);
	ft_sort(intra_rep, path, option);
	while (intra_rep && intra_rep[j])
	{
		tmp = ft_clean_path(path, intra_rep[j]);
		if (intra_rep[j][0] != '.' && (lstat(tmp, &buf) == 0
			&& S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode)))
		{
			ft_tmp_ls(path, intra_rep[j], i, option);
		}
		ft_strdel(&tmp);
		j++;
	}
	ft_free_tab(intra_rep);
	return (1);
}

void		ft_rep_tab(char **rep_tab, int i, char *option)
{
	int			j;
	struct stat	buf;

	j = 0;
	while (rep_tab && rep_tab[j])
	{	
		if (ft_strchr(option, 'l') == NULL)
			ft_display_rep(rep_tab[j], option, i);
		i++;
		if (rep_tab[j + 1] && ft_strchr(option, 'R') == NULL
			&& ft_strchr(option, 'l') == NULL)
			write(1, "\n", 1);
		if (option && ft_strchr(option, 'R') != NULL 
			&& (stat(rep_tab[j], &buf) == 0) && S_ISDIR(buf.st_mode))
		{
			ft_recursive_ls(rep_tab[j], option, i++);
			if (rep_tab[j + 1])
			{
				write(1, "\n", 1);
			}
		}
		j++;
		i++;
	}
}

void		ft_ls(char **path, char *option, int i)
{
	char		**rep_tab;
	char		**file_tab;

	ft_sort(path, NULL, option);
	ft_separate_path(path, &rep_tab, &file_tab);
	if (ft_strchr(option, 'l') != NULL)
	{
		ft_opt_long(path, option, 0);
		if (file_tab)
			ft_free_tab(file_tab);
	}
	if (file_tab && ft_strchr(option, 'l') == NULL)
	{
		ft_display(NULL, file_tab, option);
		ft_free_tab(file_tab);
		if (rep_tab)
			write(1, "\n", 1);
	}
	if (rep_tab)
	{
		ft_sort(rep_tab, NULL, option);
		ft_rep_tab(rep_tab, i, option);
		ft_free_tab(rep_tab);
	}
}

int			main(int ac, char **av)
{
	char		*option;
	char		**path;
	int			i;

	path = NULL;
	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	i =  1;
	if (path && ft_len_tab(path) > 1)
		i = 2;
	path = ft_verif_folders(path);
	if (!path)
		path = ft_create_path();
	if (path)
	{
		ft_sort_by_ascii(path);
		ft_ls(path, option, i);
		ft_free_tab(path);
	}
	ft_strdel(&option);
	return (1);
}







