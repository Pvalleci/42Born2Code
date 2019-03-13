#include "ft_ls.h"

void		ft_ls_recusive(t_list_ls *list_ls, char *name, char *option)
{
	char		*tmp;
	char		*tmp2;

	list_ls = list_ls->next->next;
	while (list_ls != NULL)
	{
		tmp2 = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp2, list_ls->name);
		ft_strdel(&tmp2);
		if (ft_check_is_rep(tmp) == 1)
		{
			printf ("\n%s: \n", tmp);
			ft_ls(tmp, option);
		}
		ft_strdel(&tmp);
		list_ls = list_ls->next;
	}
}