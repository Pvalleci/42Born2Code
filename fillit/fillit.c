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

char		*ft_get_tetriminos(int fd)
{
	char	*str;
	char	*buf;
	char	*tmp;
	int		i;

	i = 0;
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &buf))
	{
		tmp = str;
		if ((i+1) % 5 == 0)
			if (buf[0] != '\0')
				return (NULL);
		if (ft_check_buf(buf) == 0)
			return (NULL);
		str = ft_strjoin(str, buf);
		free(tmp);
		free(buf);
		i++;
	}
	if (((i + 1) % 5) != 0)
		return (NULL);
	return (str);
}

t_tetri		*ft_create_list(t_tetri *list, char *str, char lettre)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(list = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(list->tab = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (j < 4)
	{
		list->tab[j] = ft_strndup((const char *)str + i, 4);
		j++;
		i = i + 4;
	}
	list->tab[j] = 0;
	list->put = 0;
	list->letter = lettre;
	if (str[i] == '\0')
		list->next = NULL;
	else
		list->next = ft_create_list(list->next, str + i, lettre + 1);
	return (list);
}

void		ft_fillit(int fd)
{
	char		*tetri;
	t_tetri		*list;

	list = NULL;
	if (!(tetri = ft_get_tetriminos(fd)))
	{
		ft_putendl("error");
		return ;
	}
	list = ft_create_list(list, tetri, 'A');
	if (list == NULL)
		return ;
	if (ft_check_list(list) == 0)
	{
		ft_putendl("error");
		return ;
	}
	ft_correct_shift(list);
	free(tetri);
	ft_solve(list);
	ft_free_list(list);
	return ;
}

int			main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./a.out target_file");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	ft_fillit(fd);
	close(fd);
	return (0);
}
