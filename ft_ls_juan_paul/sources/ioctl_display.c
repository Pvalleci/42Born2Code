
#include "ft_ls.h"

int			ft_get_len_max(char **tab)
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

int			ft_get_number_by_col(int nb_column, int nb_elem)
{
	int nb_elem_by_col;

	nb_elem_by_col = nb_elem / nb_column;
	while ((nb_elem_by_col * nb_column) < nb_elem)
		nb_elem_by_col++;
	return (nb_elem_by_col);
}

char		*ft_get_buf(char *str, int len_max)
{
	int		i;
	char	*ret;
	i = 0;
	ret = ft_strnew(len_max);
	ft_strcpy(ret, str);
	i = ft_strlen(str);
	while (i < len_max)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void		ft_buf_tab(char **tab, int len_max)
{
	int		i;
	int		j;
	char 	*tmp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		tmp = tab[i];
		tab[i] = ft_strnew(len_max);
		while (tmp[j])
		{
			tab[i][j] = tmp[j];
			j++;
		}
		while (j < len_max)
		{
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char		**ft_tab_ioctl(char **tab, int nb_line)
{
	char		**tmp;
	char		*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * nb_line + 1)))
		return (NULL);
	while (i < nb_line)
	{
		tmp[i] = ft_strnew(0);
		i++;
	}
	i = 0;
	while (tab[j])
	{
		temp = tmp[i];
		tmp[i] = ft_strjoin(tmp[i], tab[j]);
		ft_strdel(&temp);
		j++;
		i++;
		if ((i % nb_line) == 0)
			i = 0;
	}
	tmp[nb_line] = NULL;
	return (tmp);
}

void		ft_display_ioctl(char *name, char **tab)
{
	struct ttysize		ts;
	char				**tmp_tab;
	int					len_max;
	int					nb_column;
	int					nb_elem_by_col;

	(void)name;
	len_max = 0;
	ioctl(0, TIOCGSIZE, &ts);
	len_max = ft_get_len_max(tab);
	if (len_max == 0)
		return ;
	nb_column = ts.ts_cols / len_max;
	len_max++;
	nb_elem_by_col = ft_get_number_by_col(nb_column, ft_len_tab(tab));
	tmp_tab = ft_copy_tab(tab);
	ft_buf_tab(tmp_tab, len_max);
	tmp_tab = ft_tab_ioctl(tmp_tab, nb_elem_by_col);
	ft_print_table(tmp_tab);
	ft_free_tab(tmp_tab);
}
