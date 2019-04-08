
#include "ft_ls.h"

static void			ft_sort_by_ascii(char **tab)//pas sur que ce soit necessaire vu qu on les recup ppar ordre ascii
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

static void			ft_rev_tab(char **tab)
{
	int		i;
	int		len;
	char	*swap;

	i = 0;
	len = 0;
	while (tab[len] != NULL)
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

void			ft_sort_tab(char *option, char **tab)
{
	ft_sort_by_ascii(tab);	
	// if (ft_strchr(option, 't') != NULL)
	// 	ft_sort_by_modif_time(tab, path);
	if (ft_strchr(option, 'r') != NULL)
		ft_rev_tab(tab);
}