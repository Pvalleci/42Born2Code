/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:12:46 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/03 15:57:40 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>
#include "libft.h"

static t_chain		*ft_new_element(int fd)
{
	t_chain		*newelem;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (!(newelem = (t_chain*)malloc(sizeof(t_chain))))
		return (NULL);
	if (!(newelem->file = (char*)malloc(sizeof(char))))
		return (NULL);
	newelem->file[0] = 0;
	newelem->fd = fd;
	newelem->index = 0;
	newelem->endfile = 0;
	newelem->next = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		newelem->endfile = newelem->endfile + ret;
		tmp = newelem->file;
		newelem->file = ft_strjoin(newelem->file, buf);
		free(tmp);
	}
	return (newelem);
}

static t_chain		*ft_search_elem(t_chain *element, int fd)
{
	if (element->fd != fd && element->next == NULL)
		return (element->next = ft_new_element(fd));
	if (element->fd != fd && element->next != NULL)
		return (ft_search_elem(element->next, fd));
	else
		return (element);
}

static char			*ft_fill_line(char *line, t_chain *maillon)
{
	int		i;
	int		v;
	char	*tmp;

	i = 0;
	v = 0;
	tmp = maillon->file + maillon->index;
	while (maillon->file[maillon->index] != '\n' &&
			maillon->index < maillon->endfile)
	{
		maillon->index++;
		i++;
	}
	maillon->index++;
	if (!(line = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (v < i)
	{
		line[v] = tmp[v];
		v++;
	}
	line[v] = '\0';
	return (line);
}

static void			clean_element(t_chain **element, t_chain **maillon)
{
	t_chain *tmp;

	tmp = *element;
	if ((*element)->fd == (*maillon)->fd)
	{
		*element = (*maillon)->next;
		free((*maillon)->file);
		(*maillon)->file = NULL;
		free(*maillon);
		*maillon = NULL;
	}
	else
	{
		while ((*element)->next->fd != (*maillon)->fd)
			*element = (*element)->next;
		(*element)->next = (*maillon)->next;
		free((*maillon)->file);
		(*maillon)->file = NULL;
		free(*maillon);
		*maillon = NULL;
		*element = tmp;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_chain	*element = NULL;
	t_chain			*maillon;
	char			buf[BUFF_SIZE];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (element == NULL)
	{
		if ((element = ft_new_element(fd)) == NULL)
			return (-1);
		maillon = element;
	}
	else
		maillon = ft_search_elem(element, fd);
	if (maillon->index < maillon->endfile)
		*line = ft_fill_line(*line, maillon);
	else
	{
		clean_element(&element, &maillon);
		return (0);
	}
	return (1);
}
