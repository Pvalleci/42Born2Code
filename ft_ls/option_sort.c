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

void			ft_sort_by_ascii(char **tab)//pas sur que ce soit necessaire vu qu on les recup ppar ordre ascii
{
	int		j;
	char	*tmp;

	j = 0;
	while (tab[j + 1])
	{
		if (ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			tmp = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = tmp;
			j = 0;
		}
		j++;
	}
}

static int		ft_timecmp(char *str1, char *str2, char *path)
{
	char		*str1_path;
	char		*str2_path;
	char		*tmp_path;
	struct stat	str1_stat;
	struct stat	str2_stat;


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
	int			i;
	char		*tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_timecmp(tab[i], tab[i + 1], path) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
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
	printf("option : %s\n", option);
	if (ft_strchr(option, 't') != NULL)
		ft_sort_by_modif_time(tab, path);
	if (ft_strchr(option, 'r') != NULL)
		ft_rev_tab(tab);
}