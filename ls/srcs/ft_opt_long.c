/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:40:33 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/16 19:40:35 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int 	ft_print_all(struct stat buf)
{

}


int		ft_print_l(char **intra, char *path, char *option)
{
	int i;
	int total;
	struct stat stats;

	i = 0;
	total = 0;
	printf("ft_print_l\n");
	while (intra[i])
	{
		if (intra[i][0] == '.' && ft_strchr(option, 'l') == NULL)
		{
			printf("intra[i][0] : %s\n", intra[i]);
		}
		else
		{
			if (lstat(intra[i], &stats) < 0)
			{
				perror("stat");
				printf("%s\n", intra[i]);
				return (-1);
			}
			total += stats.st_blocks;
		}
		i++;
	}
	printf ("total : %d\n", total);
	printf("path : %s\n", path);
	printf("opt : %s\n", option);
	return (0);
}

void	ft_opt_long(char **tab, char *option)
{
	char 		**intra;
	int 		i;
	int 		len;
	struct stat	buf;

	i = 0;
	len = ft_len_tab(tab);
	ft_print_table(tab);
	while (tab[i])
	{
		if (len > 1)
			printf("%s:\n", tab[i]);
		if (lstat(tab[i], &buf) == 0 && S_ISDIR(buf.st_mode))
		{	
			printf("IS_DIR\n");
			intra = ft_get_intra_rep(tab[i]);
			ft_sort(intra, tab[i], option);
			ft_print_l(intra, tab[i], option);
			ft_free_tab(intra);
		}
		else if (!(S_ISDIR(buf.st_mode)))
		{
			printf("rights nb user term ?, date %s\n", tab[i]);
		}
		i++;
	}
}