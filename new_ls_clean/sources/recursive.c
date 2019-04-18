
#include "ft_ls.h"

char		*ft_get_clan_path(char *name, char *rdir_name)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (name[ft_strlen(name)] != '/' && rdir_name[0] != '/')
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

void		ft_recursive_ls(char *name, char **path, char *option)
{
	int 				i;
	struct stat			buf;
	char				**tmp_tab;

	i = 0;
	while (path[i] != NULL && path[i][0] == '.' && (path[i][1] == '\0' || path[i][1] == '.'))
		i++;
	if (path[i] == NULL)
		return ;
	while (path[i])
	{
		if (path[i][0] == '.' && ft_strchr(option, 'a') == NULL)
			i++;
		else 
		{
			path[i] = ft_get_clan_path(name, path[i]);
			if (stat(path[i], &buf) == 0 && S_ISDIR(buf.st_mode))
			{

					printf("%s:\n", path[i]);

					tmp_tab = malloc(sizeof(char *) * 2);
					tmp_tab[0] = ft_strdup(path[i]);
					tmp_tab[1] = NULL;
					ft_ls(tmp_tab, option, 0);
			 		ft_free_tab(tmp_tab);
			}
			i++;
		}
	}
}