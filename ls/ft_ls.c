
#include "ft_ls.h"

char		*ft_clean_path(char *path, char *rep)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path , "/");
	tmp2 = ft_strjoin(tmp, rep);
	ft_strdel(&tmp);
	return (tmp2);
}

char		**ft_create_path(void)
{
	char **path;

	if (!(path = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	path[0] = ft_strdup(".");
	path[1] = NULL;
	return (path);
}

void		ft_recursive_ls(char *path, char *option, int i)
{
	char	*tmp;
	char	**intra_rep;
	char	**tmp_recur;
	int 	j;
	struct stat buf;
	intra_rep = NULL;
	j = 0;
	intra_rep = ft_get_intra_rep(path);
	//sort intra_rep
	ft_sort_by_ascii(intra_rep);
	while (intra_rep[j])
	{
		tmp = ft_clean_path(path, intra_rep[j]);
		if (intra_rep[j][0] != '.' && (stat(tmp, &buf) == 0 && S_ISDIR(buf.st_mode)))//a modifier je pense
		{
			if (!(tmp_recur = (char **)malloc(sizeof(char *) * 2)))
				return ;
			tmp_recur[0] = ft_strjoin(ft_strjoin(path, "/"), intra_rep[j]);//leaks
			tmp_recur[1] = NULL;
			write(1, "\n", 1);
			ft_ls(tmp_recur, option, j);
			ft_free_tab(tmp_recur);
		}
		ft_strdel(&tmp);
		j++;
	}
	ft_free_tab(intra_rep);
}

void		ft_ls(char **path, char *option, int i)
{
	int			j;
	char		**rep_tab;
	char		**file_tab;
	struct stat buf;

	rep_tab = NULL;
	file_tab = NULL;
	j = 0;
	ft_separate_path(path, &rep_tab, &file_tab);
	if (file_tab)
	{
		ft_display(NULL, file_tab, option, i);
		ft_free_tab(file_tab);
		if (rep_tab)
			write(1, "\n", 1);
	}
	while (rep_tab && rep_tab[j])
	{
		ft_display_rep(rep_tab[j], option, i);
		if (rep_tab[j + 1] != NULL)
			write(1, "\n", 1);
		if (option && ft_strchr(option, 'R') != NULL && (stat(rep_tab[j], &buf) == 0) && S_ISDIR(buf.st_mode))
			ft_recursive_ls(rep_tab[j], option, i);
		j++;
		i++;
	}
	if (rep_tab)
		ft_free_tab(rep_tab);
}

int		main(int ac, char **av)
{
	char		*option;
	char		**path;
	int			i;

	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	i=  1;
	if (ft_len_tab(path) > 1)
		i = 2;
	ft_sort_by_ascii(path);
	path = ft_verif_folders(path);
	if (!path)
		path = ft_create_path();
	if (path)
	{
		ft_ls(path, option, i);
		ft_free_tab(path);
	}
	free(option);
	return 1;
}