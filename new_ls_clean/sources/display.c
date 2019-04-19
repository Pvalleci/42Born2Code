
#include "ft_ls.h"

char		**ft_create_file_tab(char **tab)
{
	int			i;
	int			len;
	char		**file_tab;
	struct stat	buf;

	i = 0;
	len = 0;
	while (tab[i])//compte le nombre de file dans tab;
	{
		stat(tab[i], &buf);
		if (S_ISREG(buf.st_mode))
			len++;
		i++;
	}
	if (len == 0)
		return (NULL);
	if (!(file_tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	file_tab[len] = NULL;
	len = 0;
	while (tab[i])//copie des files dans file_tab
	{
		stat(tab[i], &buf);
		if (S_ISREG(buf.st_mode))
		{
			file_tab[len] = ft_strdup(tab[i]);
			len++;
		}
		i++;
	}
	return (file_tab);
}

char		**ft_create_rep_tab(char **tab)
{
	int			i;
	int			len;
	char		**file_tab;
	struct stat	buf;

	i = 0;
	len = 0;
	while (tab[i])//compte le nombre de file dans tab;
	{
		stat(tab[i], &buf);
		if (S_ISDIR(buf.st_mode))
			len++;
		i++;
	}
	if (len == 0)
		return (NULL);
	if (!(file_tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	file_tab[len] = NULL;
	len = 0;
	while (tab[i])//copie des files dans file_tab
	{
		stat(tab[i], &buf);
		if (S_ISDIR(buf.st_mode))
		{
			file_tab[len] = ft_strdup(tab[i]);
			len++;
		}
		i++;
	}
	return (file_tab);
}

char		**ft_get_intra_rep(char *rep)
{
	char			**intra_rep;
	DIR				*opdir;
	struct dirent	*rdir;
	int 			len;

	len = 0;	
	if (!(opdir = opendir((const char *)rep)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
		len++;
	closedir(opdir);
	if (!(intra_rep = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	if (!(opdir = opendir((const char *)rep)))		
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
	{
		intra_rep[len] = ft_strdup(rdir->d_name);
		len++;
	}
	intra_rep[len] = NULL;
	closedir(opdir);
	return (intra_rep);
}

void		ft_display_rep(char **tab, char **rep_tab, char *option, int j)
{
	int		i;
	char	**tmp_tab;
	struct stat buf;
	
	i = 0;
	while (rep_tab[i])
	{
		if (j > 1)
			printf("%s:\n", rep_tab[i]);
		if (stat(rep_tab[i], &buf) == 0 && S_ISDIR(buf.st_mode))
			tmp_tab = ft_get_intra_rep(rep_tab[i]);
		if (tmp_tab)
		{
			ft_display_ioctl(tab, tmp_tab, option);
			if (ft_strchr(option, 'R') != NULL)
			{

				ft_recursive_ls(rep_tab[i], tmp_tab, option);
			}
		}
		i++;
		if (rep_tab[i])
			write(1, "\n", 1);
	}

}

void		ft_display(char **tab, char *option, int i)
{
	char		**file_tab;
	char		**rep_tab;

	file_tab = ft_create_file_tab(tab);
	rep_tab = ft_create_rep_tab(tab);
	// if (ft_strchr(option, 'l') != NULL)
	// 	return (ft_display_right(tab, option, i)); ----------- Va Appel Fonction Pour "-l"''
	if (ft_len_tab(tab) == 1 && ft_strchr(option, 'R') == NULL && !file_tab)
	{
		file_tab = ft_get_intra_rep(tab[0]);
		ft_display_ioctl(tab, file_tab, option);
		ft_free_tab(file_tab);
	}
	else if (file_tab && !rep_tab)
	{
		ft_display_ioctl(tab, file_tab, option);
		ft_free_tab(file_tab);
	}
	else if (rep_tab)
	{
		if (file_tab)
		{
			ft_display_ioctl(tab, file_tab, option);
			ft_free_tab(file_tab);
			write(1, "\n", 1);
		}
		ft_sort_tab(option, rep_tab);
		ft_display_rep(tab, rep_tab, option, i);
	}
}