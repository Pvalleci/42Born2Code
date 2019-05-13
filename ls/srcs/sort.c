
#include "ft_ls.h"

void			ft_sort_by_ascii(char **tab)//pas sur que ce soit necessaire vu qu on les recup ppar ordre ascii
{
	int		i;
	int		booli;
	int		taille;
	char	*tmp;

	i = 0;
	taille = ft_len_tab(tab);
	booli = 1;
	while (booli == 1)
	{
		booli = 0;
		i = 0;
		while (i < taille - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				booli = 1;
			}
			i++;
		}
		taille--;
	}
}

static void		ft_rev_tab(char **tab)
{
	int		i;
	int		len;
	char	*swap;

	i = 0;
	len = 0;
	while (tab && tab[len] != NULL)
		len++;
	len--;
	while (i < len)
	{
		swap = tab[i];
		tab[i] = tab[len];
		tab[len] = swap;
		i++;
		len--;
	}
}

int			ft_cmp_tmp(char *tab, char *tab2, char *path)
{
	struct stat buf;
	struct stat buf2;
	char		*tmp;
	char		*tmp2;

	if (path)
	{
		tmp = ft_clean_path(path, tab);
		tmp2 = ft_clean_path(path, tab2);
	}
	else
	{
		tmp = ft_strdup(tab);
		tmp2 = ft_strdup(tab2);
	}
	if ((stat(tmp, &buf) == 1) || stat(tmp2, &buf2))
		return (0);
	else
		if (buf.st_mtime < buf2.st_mtime)
		{
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			return (-1);
		}
	return(0);
}

void		ft_sort_m_time(char **tab, char *path)
{

	int		i;
	char	*swap;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i + 1] && ft_cmp_tmp(tab[i], tab[i + 1], path) == -1)
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else 
			i++;
	}


}

void		ft_sort(char **tab, char *path, char *option)
{
	(void)path;
	ft_sort_by_ascii(tab);
	if (ft_strchr(option, 't'))
		ft_sort_m_time(tab, path);
	if (ft_strchr(option, 'r') != NULL)
	{
		ft_rev_tab(tab);
	}

}