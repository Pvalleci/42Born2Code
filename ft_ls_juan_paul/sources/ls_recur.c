#include "ft_ls.h"


char		*ft_get_clean_path(char *tab, char *name)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strcmp(name, "/") != 0)
	{
		tmp2 = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp2, tab);
		ft_strdel(&tmp2);
	}
	else
		tmp = ft_strjoin(name, tab);
	return (tmp);
}

void		ft_ls_recusive(char **tab, char *name, char *option, int nb_path)
{
	char		*tmp;
	int			i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], ".") == 0 || ft_strcmp(tab[i], "..") == 0)
			i++;
		else
		{
			tmp = ft_get_clean_path(tab[i], name);
			if (ft_check_is_rep(tmp) == 1)
			{
				printf("%s:\n", tmp);
				ft_ls(tmp, option, nb_path);
			}
			ft_strdel(&tmp);
			i++;
		}
	}
}