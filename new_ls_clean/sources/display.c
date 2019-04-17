
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

void		ft_display_rep(char **file_tab, char **rep_tab, char *option)
{
	char		**tmp_tab;
	int			i;

	i = 0;
	if (file_tab == NULL && ft_len_tab(rep_tab) == 1)
	{
		tmp_tab = ft_get_intra_rep(rep_tab[i]);
		if (!tmp_tab)
			return;
		else
			ft_display_ioctl(tmp_tab, option);
	}
	else
	{
		while (rep_tab[i])
		{
			if (i == 0)
				printf("\n");
			tmp_tab = ft_get_intra_rep(rep_tab[i]);
			if (tmp_tab)
			{	
				printf("%s:\n", rep_tab[i]);
				ft_display_ioctl(tmp_tab, option);
			}
			if (rep_tab[i + 1] != NULL)
				ft_putchar('\n');
			i++;
		}
	}
}

void		ft_display(char **tab, char *option)
{
	char		**file_tab;
	char		**rep_tab;

	file_tab = ft_create_file_tab(tab);
	rep_tab = ft_create_rep_tab(tab);
	if (file_tab)
	{
		ft_sort_tab(option, file_tab);
		ft_display_ioctl(file_tab, option);
		ft_putendl("");
	}
	if (rep_tab)
	{
		ft_display_rep(file_tab, rep_tab, option);
		ft_free_tab(rep_tab);
		if (file_tab)
			ft_free_tab(file_tab);
	}
	//ioctl sur file tab;
	//afficher rep_tab[n] puis son contenu en ioctl
}