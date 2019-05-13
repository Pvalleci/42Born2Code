
#include "ft_ls.h"

char		*ft_clean_path(char *path, char *rep)
{
	char	*tmp;
	char	*tmp2;

//	printf("path : %s\nrep : %s\n", path, rep);

	if (ft_only_char(path, '/') == 1)
	{
		if (!(tmp = ft_strdup(path)))
			return (NULL);
	}
	else
		if (!(tmp = ft_strjoin(path , "/")))
			return (NULL);
	if (!(tmp2 = ft_strjoin(tmp, rep)))
		return (NULL);
	ft_strdel(&tmp);
	return (tmp2);
}

char		**ft_create_path(void)
{
	char **path;

	if (!(path = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	if (!(path[0] = ft_strdup(".")))
		return (NULL);
	path[1] = NULL;
	return (path);
}

char 		**ft_create_tmp(char *path, char *intra_rep)
{
	char **tmp_recur;

	if (!(tmp_recur = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);

	tmp_recur[0] = ft_clean_path(path, intra_rep);
	tmp_recur[1] = NULL;
	return (tmp_recur);
}

int		ft_recursive_ls(char *path, char *option, int i)
{
	char	*tmp;
	char	**intra_rep;
	char	**tmp_recur;
	int 	j;
	struct stat buf;

	intra_rep = NULL;
	j = 0;
	if (!(intra_rep = ft_get_intra_rep(path)) || (ft_filter_recursive(option, intra_rep) == -1))
	{
		return (-1);
	}
	ft_sort(intra_rep, NULL, option);
	while (intra_rep && intra_rep[j])
	{
		tmp = ft_clean_path(path, intra_rep[j]);
		if (intra_rep[j][0] != '.' && (stat(tmp, &buf) == 0 && S_ISDIR(buf.st_mode)))//a modifier je pense
		{
			if ((tmp_recur = ft_create_tmp(path, intra_rep[j])))
			 	write(1, "\n", 1);
			ft_ls(tmp_recur, option, i);
			ft_free_tab(tmp_recur);
		}
		ft_strdel(&tmp);
		j++;
	}
	ft_free_tab(intra_rep);
	return (1);
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
	ft_sort(path, NULL, option);
	ft_separate_path(path, &rep_tab, &file_tab);
	if (!file_tab && !rep_tab)
		ft_display(NULL, path, option);
	if (file_tab)
	{
		ft_display(NULL, file_tab, option);
		ft_free_tab(file_tab);
		if (rep_tab && ft_strchr(option, 'R') == NULL)
		{
			write(1, "\n", 1);
		}
	}
	if (rep_tab)
	{
		ft_sort(rep_tab, NULL, option);
	}
	while (rep_tab && rep_tab[j])
	{		
		ft_display_rep(rep_tab[j], option, i);
		i++;
		if (rep_tab[j + 1] && ft_strchr(option, 'R') == NULL)// if (ft_check_space(rep_tab, j, option) == 1)//rep_tab[j + 1] != NULL && ft_strchr(option, 'R') == NULL
			write(1, "\n", 1);
		if (option && ft_strchr(option, 'R') != NULL 
			&& (stat(rep_tab[j], &buf) == 0) && S_ISDIR(buf.st_mode))
		{
			ft_recursive_ls(rep_tab[j], option, i++);
			if (rep_tab[j + 1])
			{
				write(1, "\n", 1);
			}
		}
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
	i =  1;
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