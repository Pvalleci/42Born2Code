/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:19:06 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 19:19:09 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_count_len_int(int nb)
{
	int			i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int			ft_link_size(char *name, char **tab)
{
	int			i;
	int			size;
	char		*tmp;
	struct stat stats;

	i = 0;
	size = 0;
	while (tab[i])
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, tab[i]);//leaks
		if (stat(tmp, &stats) < 0)
			return (0);
		if (ft_count_len_int(stats.st_nlink) > size)
			size = ft_count_len_int(stats.st_nlink);
		i++;
	}
	return (size);
}

void		ft_display(char *name, char **tab, char *option, int nb_path)
{
	if (nb_path > 1)
		printf("%s:\n", name);
	if (ft_strchr(option, 'l'))
		ft_print_l(name, tab);
	else
		ft_display_ioctl(name, tab);
	printf("\n");
}
