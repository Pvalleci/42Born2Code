/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 02:00:49 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/14 17:53:18 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void			ft_sort_by_ascii(char **tab)
{
	int		i;
	int		j;
	int		len;
	int		best;

	i = 0;
	len = ft_len_tab(tab);
	while (tab[i])
	{
		j = 0;
		best = i;
		while (tab[j])
		{
			if (tab[j] && tab[j + 1] && ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap_str(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

static void		ft_rev_tab(char **tab)
{
	int		i;
	int		len;
	char	*swap;

	i = 0;
	len = 0;
	while (tab && tab[len] != NULL)
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


void	ft_buf(char *path, char *s, char *buf)
{
	int	i;

	i = 0;
	if (path)
	{
		i = ft_strlen(path);
		ft_strcpy(buf, path);
		ft_strcpy((buf + i), "/");
		i++;
	}
	ft_strcpy(buf + i, s);
	return ;
}

int			ft_cmp_tmp(char *s1, char *s2, char *path)
{
	struct stat sb1;
	struct stat sb2;
	char  	buf1[125];
	char 	buf2[125];

	ft_buf(path, s1, buf1);
	ft_buf(path, s2, buf2);
	if (stat(buf1, &sb1) != 0)
		return (-2);
	if (stat(buf2, &sb2) != 0)
		return (-2);
	if (sb1.st_mtime < sb2.st_mtime)
		return (1);
	else if (sb1.st_mtime > sb2.st_mtime)
		return (-1);
	else if (sb1.st_mtime == sb2.st_mtime)
	{
		if (sb1.st_mtimespec.tv_nsec < sb2.st_mtimespec.tv_nsec)
			return (1);
	}
	return (0);
}


void		ft_sort_m_time(char **tab, char *path)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (tab[j] && tab[j + 1] && (ft_cmp_tmp(tab[j] , tab[j + 1], path)) == 1)
			{
				ft_swap_str(&tab[j], &tab[j + 1]);
				j = -1;
			}
			j++;
		}
		i++;
	}
}

void		ft_sort(char **tab, char *path, char *option)
{
	ft_sort_by_ascii(tab);
	if (ft_strchr(option, 't'))
 	{
		ft_sort_m_time(tab, path);
	}
	if (ft_strchr(option, 'r') != NULL)
	{
		ft_rev_tab(tab);
	}
}

