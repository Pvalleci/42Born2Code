
#include "ft_ls.h"

int			ft_get_len_max(char **tab)//a mettre ds tools
{
	int		i;
	int		tmp;
	int		len_max;

	i = 0;
	len_max = 0;
	while (tab[i])
	{
		if ((tmp = ft_strlen(tab[i])) > len_max)
			len_max = tmp;
		i++;
	}
	return (len_max);
}

void		ft_display_ioctl(char **file_tab, char *option)
{
	struct ttysize		ts;
	char				**tmp_tab;
	int					len_max;
	int					nb_column;
	int					nb_elem_by_col;

	ft_sort_by_ascii(file_tab);
	ioctl(0, TIOCGSIZE, &ts);
	tmp_tab = ft_copy_tab(file_tab);	
	tmp_tab = ft_clean_tab(tmp_tab, option);
	len_max = ft_get_len_max(tmp_tab) + 1;
	nb_column = ts.ts_cols / (len_max);
	if (nb_column == 0)
		nb_column++;
	while ((nb_column * ((ft_len_tab(tmp_tab) / nb_column))) > (ft_len_tab(tmp_tab) + ((ft_len_tab(tmp_tab) / nb_column) + 1)))
			nb_column--;
	if ((nb_column * len_max) > ts.ts_cols)
		nb_column--;
	tmp_tab = ft_buf_tab(tmp_tab, nb_column, nb_column * len_max, len_max);
	ft_print_table(tmp_tab);
	ft_free_tab(tmp_tab);
}
