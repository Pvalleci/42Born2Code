/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:51:24 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/18 22:51:29 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_get_tetriminos(int	fd)
{
	char	*str;
	char	*buf;
	char	*tmp;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &buf))
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
		free(buf);
	}
	return (str);
}

t_tetri		*ft_create_list(t_tetri *list, char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	list = (t_tetri *)malloc(sizeof(t_tetri));
	list->tab = (char **)malloc(sizeof(char *) * 5);
	while (j < 4)
	{
		list->tab[j] = ft_strndup((const char *)str + i, 4);
		j++;
		i = i + 4;
	}
	list->put = 0;
	if (str[i] == '\0')
		list->next = NULL;
	else
		list->next = ft_create_list(list->next, str + i);
	return (list);
}


void		ft_fillit(int fd)
{
	char 	*tetri;
	t_tetri	*list;

	tetri = ft_get_tetriminos(fd);
	printf("tetri : [%s]\n", tetri);
	list = ft_create_list(list, tetri);
	ft_correct_shift(list);
	free(tetri);
	ft_affiche_list(list);
	ft_solve(list);
	return ;
}


int		main(int argc, char **argv)
{
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	ft_fillit(fd);
	close(fd);
	return (0);
}
