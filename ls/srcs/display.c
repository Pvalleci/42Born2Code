/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 01:59:37 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/15 16:03:15 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_len_rep(char *rep)
{
	int		len;
	DIR				*opdir;
	struct dirent	*rdir;	

	len = 0;
	if (!(opdir = opendir((const char *)rep)))//ouverture repertoire
		return (-1);
	while ((rdir = readdir(opdir)) != NULL)//calcul longueur rep
		len++;
	closedir(opdir);
	return (len);
}

char		**ft_get_intra_rep(char *rep)
{
	char			**intra_rep;
	DIR				*opdir;
	struct dirent	*rdir;
	int 			len;

	len = ft_len_rep(rep);
	if (len == -1)
		return (NULL);
	if (!(intra_rep = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	if (!(opdir = opendir((const char *)rep)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
	{
		intra_rep[len] = ft_strdup(rdir->d_name);
		len++;
	}
	intra_rep[len] = NULL;
	closedir(opdir);
	return (intra_rep);
}

void		ft_display(char *path, char **file_tab, char *option)
{
	ft_sort(file_tab, path, option);
	if (ft_strchr(option, 'l'))
	{
		ft_opt_long(file_tab, option);
	}
	else
		ft_display_ioctl(file_tab, option);
}

void		ft_display_rep(char *path, char *option, int i)
{
	char		**intra_rep;

	intra_rep = NULL;
	if (i > 1 && path && ft_strchr(option, 'l') == NULL)
		printf("%s:\n", path);
	if (path)
		intra_rep = ft_get_intra_rep(path);
	if (ft_strchr(option, 'l') != NULL)
		ft_opt_long(intra_rep, option);
	else if (intra_rep)
	{
		if (ft_strchr(option, 'l') == NULL)
			ft_display(path, intra_rep, option);
		ft_free_tab(intra_rep);
	}
	else
	{
		intra_rep = NULL;
		printf("ft_ls: %s: Permission denied\n", path);
	}
}
