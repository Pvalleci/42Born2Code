
#include "ft_ls.h"

int		ft_is_not_directory(char *str)
{
	int				a;
	char			*s;
	struct stat		buf;

	s = ft_strdup(str);
	if (!s)
		return (-1);
	a = ft_strlen(s) - 1;
	while (s[a] == '/')
	{
		s[a] = '\0';
		a--;
	}
	if ((stat(s, &buf)) < 0)
	{
		ft_strdel(&s);
		return (1);
	}
	ft_strdel(&s);
	return (0);
}

int				ft_len_tab(char **tab)//dans certains cas il y a unprobleme avecceque recoit la fonction...
{
	int		i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i] != NULL)
		i++;
	return (i);

}

static char		**ft_create_file_tab(char **tab)
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

static char		**ft_create_rep_tab(char **tab)
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

void		ft_separate_path(char **path, char ***rep_tab, char ***file_tab)
{
	*file_tab = ft_create_file_tab(path);
	*rep_tab = ft_create_rep_tab(path);
}

int 		ft_only_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
