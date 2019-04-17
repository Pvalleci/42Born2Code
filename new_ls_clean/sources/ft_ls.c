
#include "ft_ls.h"


char		**ft_create_path(void)
{
	char **path;

	if (!(path = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	path[0] = ft_strdup(".");
	path[1] = NULL;
	return (path);
}

void		ft_ls(char **path, char *option, int i)
{
	ft_sort_tab(option, path);
	ft_display(path, option, i);

}

int		main(int ac, char **av)
{
	char		*option;
	char		**path;
	int			i;

	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	i = ft_len_tab(path);
	ft_sort_tab(NULL, path);
	path = ft_verif_folders(path);
	if (!path)
		path = ft_create_path();
	if (path)
		ft_ls(path, option, i);
	ft_free_tab(path);
	free(option);
	return 1;
}