/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:27:50 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 16:27:55 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void		ft_aff_list(t_list_ls *list)/////////////////////////
// {
// 	while (list != NULL)
// 	{
// 		printf("list : %s\n", list->name);
// 		list = list->next;
// 	}
// }


char				**ft_copy_tab(char **tab)
{
	char			**tmp_tab;
	int				i;

	i = 0;
	if (!(tmp_tab = (char **)malloc(sizeof(char *) * ft_len_tab(tab) + 1)))
		return (NULL);
	while (tab[i])
	{
		tmp_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp_tab[i] = NULL;
	return (tmp_tab);
}

static t_list_ls	*ft_create_elem(DIR *rep)
{
	t_list_ls		*list;
	struct dirent	*dir;

	if(!(dir = readdir(rep)))
		return (NULL);
	if (!(list = malloc(sizeof(t_list_ls))))
		return (NULL);
	if (!(list->name = ft_strdup(dir->d_name)))
		return (NULL);
	list->next = ft_create_elem(rep);
	return (list);
}

t_list_ls			*ft_create_list(char *name)
{

	t_list_ls		*list;
	DIR				*rep;

	if (!(rep = opendir(name)))
		return (NULL);
	list = ft_create_elem(rep);
	closedir(rep);
	return (list);
}

char			**ft_to_tab(t_list_ls *list, char *option)
{
	int			nb_element;
	t_list_ls	*start;
	char		**tab;

	nb_element = 0;
	start = list;
	while (list != NULL)//peut etre mis dans une ft genre ft_len_list(list) et renvoit un int
	{
		nb_element++;
		list = list->next;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_element + 1))))
		return (NULL);
	nb_element = 0;
	while (start != NULL)
		if (ft_strchr(option, 'a') == NULL && start->name[0] == '.')
			start = start->next;
		else
		{
			if (!(tab[nb_element] = ft_strdup(start->name)))
				return (NULL);
			nb_element++;
			start = start->next;
		}
	tab[nb_element] = NULL;
	return (tab);
}
