
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

void		ft_ls(char **path, char *option)
{
	ft_sort_tab(option, path);
	ft_display(path, option);
	if (ft_strchr(option, 'R') != NULL)
	{
		ft_recursive_ls(path, option);
		// ft_free_tab(path); pb avec ce free je sais paspourquoi...
	}
}

int		main(int ac, char **av)
{
	char		*option;
	char		**path;

	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	path = ft_verif_folders(path);
	if (!path)
		path = ft_create_path();
	if (path)
		ft_ls(path, option);
	ft_free_tab(path);
	free(option);
	return 1;
}