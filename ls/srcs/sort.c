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
			if (tab[j] && tab[j + 1] && ft_strcmp(tab[j], tab[j + 1]) < 0)
			{
				// printf("swap de : %s ET %s\n", tab[j], tab[j+ 1]);
				ft_swap_str(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		// ft_swap_str(&tab[best], &tab[i]);
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

int				ft_cmp_tmp(char *tab, char *tab2, char *path)
{
	printf("ft_cmp_tmp\n");
	struct stat buf;
	struct stat buf2;
	char		*tmp;
	char		*tmp2;
	int			retour;

	if (path)
	{
		tmp = ft_clean_path(path, tab);
		tmp2 = ft_clean_path(path, tab2);
	}
	else
	{
		tmp = ft_strdup(tab);
		tmp2 = ft_strdup(tab2);
	}
	printf("tmp : %s\n", tmp);
	printf("tmp2 : %s\n", tmp2);
	if ((stat(tmp, &buf) != 0) || ((stat(tmp2, &buf2)) != 0))
	{

		retour = 0;
		printf("stat error\n");
	}
	else if (buf.st_mtime < buf2.st_mtime)
		retour = 1;
	else if (buf.st_mtime > buf2.st_mtime)
		retour = -1;
	else
		retour = 0;
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (retour);
}

void		ft_sort_m_time(char **tab, char *path)
{
	// int end;

	// end = ft_len_tab(tab);
	// printf("end : %d\n", end);
	// ft_quicksort(tab, 0, end - 1, ft_cmp_tmp, path);
	// printf("fin quicksort\n");
	int		i;
	char	*swap;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i + 1] && ft_cmp_tmp(tab[i], tab[i + 1], path) == -1)
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

static void	ft_quicksort_mtime(char **number, int first, int last, char *path)
{
	int i, j, pivot;
	char *temp;

	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(ft_cmp_tmp(number[i], number[pivot], path) <= 0 && i < last)//condition a changer
				i++;
			while(ft_cmp_tmp(number[j], number[pivot], path) > 0)//condition a changer
				j--;
			if(i < j)
			{
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
		temp=number[pivot];
		number[pivot]=number[j];
		number[j]=temp;
		ft_quicksort_mtime(number,first,j-1, path);
		ft_quicksort_mtime(number,j+1,last, path);
	}
}


static void	ft_quicksort_ascii(char **number, int first, int last, int (*f)(const char *, const char *))
{
	int i, j, pivot;
	char *temp;

	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			// printf("while i < j\n");
			while(f(number[i], number[pivot]) <= 0 && i < last)//condition a changer
			{	
				// printf("i : %d\n" , i );
				i++;
			}
			while(f(number[j], number[pivot]) > 0)//condition a changer
			{
				// printf("j : %d\n", j);
				j--;
			}
			if(i < j)
			{
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
		temp=number[pivot];
		number[pivot]=number[j];
		number[j]=temp;
		ft_quicksort_ascii(number,first,j-1, f);
		ft_quicksort_ascii(number,j+1,last, f);
	}
}

void		ft_sort(char **tab, char *path, char *option)
{
	// printf("sort\n");
	ft_quicksort_ascii(tab, 0, ft_len_tab(tab) - 1, &ft_strcmp);//trie par ordre ascii
	// printf("fin sort\n");
	if (ft_strchr(option, 't'))
 	{
 		ft_quicksort_mtime(tab, 0, ft_len_tab(tab) - 1, path);
		// ft_sort_m_time(tab, path);
	}
	if (ft_strchr(option, 'r') != NULL)
	{
		ft_rev_tab(tab);
	}
}