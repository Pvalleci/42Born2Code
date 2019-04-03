
#include "ft_ls.h"


void			ft_aff_tab(char **tab, char *option)
{
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (ft_strchr(option, 'a'))
		a = 1;
	while (tab[i])
	{
		if (a == 0 && tab[i][0] == '.')
			i++;
		else
		{
			ft_putendl(tab[i]);
			i++;
		}
	}
}


int				ft_len_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);

}

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