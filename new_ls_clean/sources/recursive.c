
#include "ft_ls.h"

char		*ft_get_clan_path(char *name, char *rdir_name)
{
	char	*str;
	char	*tmp;

	str = NULL;
	//si j ai / return / ---------a faire
	if (name[ft_strlen(name)] != '/')
	{
		str = ft_strjoin(name, "/");
	}
	tmp = str;
	str = ft_strjoin(str, rdir_name);
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
	{
		if (rdir->d_type == DT_DIR)
			i++;
	}
	closedir(opdir);
	if (i == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	if (!(opdir = opendir(list->name)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
	{
		if (rdir->d_type == DT_DIR)
		{
			tab[i] = ft_get_clan_path(list->name, rdir->d_name);
			i++;
		}
	}
	tab[i] = NULL;
	closedir(opdir);
	return (tab);
}

void		ft_recursive_ls(char **path, char *option)
{
	// t_list_ls 			*list;
	// t_list_ls			*start;
	char				**in_path;
	int i;

	i = 0;
	printf("tmp_tab	de ft_recursive_ls\n");
	printf("-----------------------------\n");
	ft_print_table(path);
	printf("-----------------------------\n");
	// list = NULL;
	// in_path = NULL;
	// list = ft_create_list(path);
	// if (!list)
	// {
	// 	printf("list NULL\n");
	// 	return ;
	// }
	// start = list;
	while (path[i])
	{
		printf("%s:\n", path[i]);
		in_path = ft_get_intra_rep(path[i]);
		ft_ls(in_path + 2, option, 0);
		ft_free_tab(in_path);
		i++;
		// in_path = ft_path_tab(list);
		// if (in_path == NULL)
		// 	list = list->next;
		// else
		// {
			
		// 	ft_ls(in_path + 2, option, 0);
		// 	ft_free_tab(in_path);
		// 	list = list->next;
		// }
	}
	// ft_free_list(start);
}