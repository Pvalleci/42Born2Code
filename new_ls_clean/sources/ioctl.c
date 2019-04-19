
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

int			ft_get_number_by_col(int nb_column, int nb_elem)
{
	int nb_elem_by_col;

	if (nb_column == 0)
		return (1);
	nb_elem_by_col = nb_elem / nb_column;
	while ((nb_elem_by_col * nb_column) < nb_elem)
		nb_elem_by_col++;
	return (nb_elem_by_col);
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
		free(tmp);
		while (j < len_max)
		{
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char		**ft_tab_ioctl(char **tab, int nb_line, int len_max, int nb_column)
{
	char		**tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * (nb_line + 1))))
		return (NULL);
	while (i < nb_line)
	{
		tmp[i] = ft_strnew(len_max * nb_column);
		i++;
	}
	i = 0;
	while (tab[j])
	{
		tmp[i] = ft_strcat(tmp[i], tab[j]);
		j++;
		i++;
		if ((i % nb_line) == 0)
			i = 0;
	}
	tmp[nb_line] = NULL;
	ft_free_tab(tab);
	return (tmp);
}

void		ft_put_end(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		j = ft_strlen(tab[i]);
		j--;
		while (tab[i][j] == ' ')
		{		
			j--;
		}
		j++;
		tab[i][j] = '\0';
		i++;
	}
}

void		ft_display_all(char **tab1, char **tab, char *option)
{
	//Faire Ce Qui Faut Ici.
	//tab1[0] ( !! Y a un zero c pas pour rien !! ) contient le path pour tes appels a stat etc.. exmple : "../toto/nom". 
	//tu join tab1[0] avec tab[i] et t as de quoi faire stat().
	//dans tab il y tout sur quoi tu dois faire un -l. C est le contenu du repertoire. 
	//pas besoin de t occuper du nom de repertoires c est deja gerer
	//je te laisse les lignes pour que tu test
	printf("ft_display_all----------------\n");
	printf("Repertoires: -----------------\n");
	ft_print_table(tab1);
	printf("-------------------------------\n");
	printf("ce sur quoi il faut faire -l : \n");
	ft_print_table(tab);
	printf("-------------------------------\n");
	(void)option;
}

void		ft_display_ioctl(char **tab1, char **tab, char *option)
{
	struct ttysize		ts;
	char				**tmp_tab;
	int					len_max;
	int					nb_column;
	int					nb_elem_by_col;

	if (ft_strchr(option, 'l') != NULL)
		return (ft_display_all(tab1, tab, option));
	len_max = 0;
	ioctl(0, TIOCGSIZE, &ts);
	tmp_tab = ft_copy_tab(tab);	
	tmp_tab = ft_clean_tab(tmp_tab, option);
	len_max = ft_get_len_max(tmp_tab);
	if (len_max == 0)
		return ;

	nb_column = ts.ts_cols / len_max;
	if (nb_column == 0)
		nb_column++;
	len_max++;
	nb_elem_by_col = ft_get_number_by_col(nb_column, ft_len_tab(tab));
	ft_buf_tab(tmp_tab, len_max);
	tmp_tab = ft_tab_ioctl(tmp_tab, nb_elem_by_col, len_max, nb_column);
	ft_put_end(tmp_tab);
	if (ft_get_len_max(tmp_tab) >= ts.ts_cols)
	{
		nb_column--;
		ft_free_tab(tmp_tab);
		len_max = 0;
		ioctl(0, TIOCGSIZE, &ts);
		tmp_tab = ft_copy_tab(tab);	
		tmp_tab = ft_clean_tab(tmp_tab, option);
		len_max = ft_get_len_max(tmp_tab);
		if (len_max == 0)
			return ;
		if (nb_column == 0)
			nb_column++;
		len_max++;
		nb_elem_by_col = ft_get_number_by_col(nb_column, ft_len_tab(tab));
		ft_buf_tab(tmp_tab, len_max);
		tmp_tab = ft_tab_ioctl(tmp_tab, nb_elem_by_col, len_max, nb_column);
		ft_put_end(tmp_tab);		
	}
	ft_aff_tab(tmp_tab);
	ft_free_tab(tmp_tab);
}