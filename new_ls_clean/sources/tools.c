
#include "ft_ls.h"


char			**ft_clean_tab(char **tab, char *option)
{
	char	**tmp_tab;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ft_strchr(option, 'a') != NULL)
		return (tab);
	while (tab[i])
	{
		if (tab[i][0] != '.')
			len++;
		i++;
	}
	if (!(tmp_tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '.')
			i++;
		else
		{
			tmp_tab[len] = ft_strdup(tab[i]);
			len++;
			i++;
		}
	}
	tmp_tab[len] = NULL;
	ft_free_tab(tab);
	return (tmp_tab);
}

void			ft_aff_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
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

char				**ft_copy_tab(char **tab)
{
	char			**tmp_tab;
	int				i;

	i = 0;
	if (!tab)
		return (NULL);
	if (!(tmp_tab = (char **)malloc(sizeof(char *) * (ft_len_tab(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		tmp_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp_tab[i] = NULL;
	return (tmp_tab);
}

t_list_ls		*ft_create_elem(char **path)
{
	int			i;
	t_list_ls	*list;
	struct stat	buf;

	i = 0;
	list = NULL;
	if (path[i])
	{
		stat(path[i], &buf);
		if (S_ISDIR(buf.st_mode))
		{
			if (!(list = (t_list_ls *)malloc(sizeof(t_list_ls))))
				return (NULL);			
			list->name = ft_strdup(path[i]);
			list->next = ft_create_elem(path + 1);
		}
		else
			list = ft_create_elem(path + 1);
	}
	return (list);
}

t_list_ls		*ft_create_list(char **path)
{
	t_list_ls	*list;

	list = NULL;
	list = ft_create_elem(path);
	return (list);
}