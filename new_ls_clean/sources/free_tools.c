
#include "ft_ls.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_free_list(t_list_ls *list)
{
	t_list_ls *tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->name);
		free(list);
		list = tmp;
	}
}