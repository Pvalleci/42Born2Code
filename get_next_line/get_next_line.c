/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:35:51 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/11 16:38:21 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_input_line(char **line, char *tab)
{
	int				i;
	char			*tmp;

	i = 0;
	if (tab && ft_strchr(tab, '\n') != NULL)
	{
		while (tab[i] != '\n')
			i++;
		*line = ft_strndup(tab, i);
		i++;
		tmp = ft_strdup(tab + i);
		free(tab);
		tab = tmp;
	}
	else if (tab != NULL && ft_strchr(tab, '\n') == NULL)
	{
		*line = ft_strdup(tab);
		free(tab);
		tab = NULL;
	}
	return (tab);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tb[OPEN_MAX];
	int				lu;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	lu = 0;
	if (!line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	while ((!tb[fd] || !ft_strchr(tb[fd], 10))
		&& (lu = read(fd, buf, BUFF_SIZE)))
	{
		buf[lu] = '\0';
		tmp = tb[fd];
		tb[fd] = tb[fd] ? ft_strjoin(tb[fd], buf) : ft_strdup(buf);
		free(tmp);
		tmp = NULL;
	}
	tmp = tb[fd];
	tb[fd] = ft_input_line(line, tb[fd]);
	if ((tb[fd] == NULL && tmp == NULL) || tmp[0] == '\0')
	{
		free(tb[fd]);
		return (0);
	}
	return (1);
}
