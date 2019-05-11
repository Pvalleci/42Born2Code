
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