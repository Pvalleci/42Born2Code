/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:01:19 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 18:01:20 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_len_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);

}

void			ft_sort_by_ascii(char **tab)//pas sur que ce soit necessaire vu qu on les recup ppar ordre ascii
{
	int		i;
	int		booli;
	int		taille;
	char	*tmp;

	i = 0;
	taille = ft_len_tab(tab);
	booli = 1;
	while (booli == 1)
	{
		booli = 0;
		i = 0;
		while (i < taille - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				booli = 1;
			}
			i++;
		}
		taille--;
	}
}

static int		ft_timecmp(char *str1, char *str2, char *path)
{
	char		*str1_path;
	char		*str2_path;
	char		*tmp_path;
	struct stat	str1_stat;
	struct stat	str2_stat;
	//leaks

	tmp_path = ft_strjoin(path, "/");
	str1_path = ft_strjoin(tmp_path, str1);
	str2_path = ft_strjoin(tmp_path, str2);
	ft_strdel(&tmp_path);
	if (!(str1_path && str2_path))
		return (0);
	if ((stat(str1_path, &str1_stat)) == -1)
		return (0);
	if ((stat(str2_path, &str2_stat)) == -1)
		return (0);
	if (str1_stat.st_mtime < str2_stat.st_mtime)
		return 1;
	return 0;
}

void			ft_sort_by_modif_time(char **tab, char *path)
{
	int		i;
	int		booli;
	int		taille;
	char	*tmp;

	i = 0;
	taille = ft_len_tab(tab);
	booli = 1;
	while (booli == 1)
	{
		booli = 0;
		i = 0;
		while (i < taille - 1)
		{
			if (ft_timecmp(tab[i], tab[i + 1], path) == 1)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				booli = 1;
			}
			i++;
		}
		taille--;
	}
}

void			ft_rev_tab(char **tab)
{
	int		i;
	int		len;
	char	*swap;

	i = 0;
	len = 0;
	while (tab[len] != NULL)
		len++;
	len--;
	while (i < len)
	{
		swap = tab[i];
		tab[i] = tab[len];
		tab[len] = swap;
		i++;
		len--;
	}
}

void			ft_sort_tab(char *path, char *option, char **tab)
{
	ft_sort_by_ascii(tab);
	if (ft_strchr(option, 't') != NULL && path != NULL)
		ft_sort_by_modif_time(tab, path);
	if (ft_strchr(option, 'r') != NULL)
		ft_rev_tab(tab);
}
