
#include "ft_ls.h"

char		*ft_get_clan_path(char *name, char *rdir_name)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (name[ft_strlen(name)] != '/')
	{
		str = ft_strjoin(name, "/");
	}
	tmp = str;
	str = ft_strjoin(name, rdir_name);
	if (tmp)
		free(tmp);
	return (str);
}

char		**ft_path_tab(t_list_ls *list)
{
	DIR				*opdir;
	struct dirent	*rdir;
	char			**tab;
	int				i;

	i = 0;
	if (!(opdir = opendir(list->name)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
		i++;
	closedir(opdir);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	if (!(opdir = opendir(list->name)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
	{
		tab[i] = ft_get_clan_path(list->name, rdir->d_name);
		i++;
	}
	tab[i] = NULL;
	closedir(opdir);
	return (tab);
}


void		ft_recursive_ls(t_list_ls *list, char *option)
{
	//1- Ouvrir list->name
	//2- Creer un tableau contenant les element dans chaque rep
	//rappel de ls avec nouveau taleau et opiton
	char			**tmp_tab;

	while (list != NULL)
	{
		tmp_tab = ft_path_tab(list);//pb de join a priori
		ft_ls(tmp_tab + 2, option);// + 2 pour passer . et ..
		list = list->next;
	}
}