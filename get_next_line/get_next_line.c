/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:31:24 by juaalvar          #+#    #+#             */
/*   Updated: 2018/12/04 17:06:42 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_listnew(void const *content, size_t content_size)
{
	t_gnl	*newlist;
	size_t	size;

	size = ft_strlen(content);
	if (!(newlist = (t_gnl*)malloc(sizeof(t_gnl) * 1)))
		return (0);
	newlist->content = ((void*)malloc(ft_strlen(content)));
	newlist->content = ft_strncpy(newlist->content, content, size);
	newlist->content_size = content_size;
	newlist->index = 0;
	newlist->nb = ft_strlen(content);
	newlist->next = NULL;
	return (newlist);
}

static char		*ft_getfile(const int fd)
{
	char	*s;
	int		nblu;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	nblu = read(fd, buf, BUFF_SIZE);
	if (nblu == -1)
		return (NULL);
	buf[nblu] = '\0';
	if (!(s = (char *)malloc(nblu)))
		return (NULL);
	s[nblu] = '\0';
	s = ft_strncpy(s, buf, nblu);
	while ((nblu = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nblu] = '\0';
		tmp = s;
		s = ft_strjoin(s, buf);
		free(tmp);
	}
	return (s);
}

static t_gnl	*ft_parcour_list(t_gnl *maillon, const int fd)
{
	if (maillon->content_size != (size_t)fd && maillon->next != NULL)
		return (ft_parcour_list(maillon->next, fd));
	if (maillon->content_size != (size_t)fd && maillon->next == NULL)
	{
		maillon->next = ft_listnew(ft_getfile(fd), fd);
		return (maillon->next);
	}
	return (maillon);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*maillon = NULL;
	t_gnl			*ptr;
	int				i;

	if (fd < 0)
		return (-1);
	if (!maillon)
		maillon = ft_listnew(ft_getfile(fd), fd);
	ptr = ft_parcour_list(maillon, fd);
	if (!ptr)
		return (-1);
	i = 0;
	while (ptr->content[ptr->index] != '\0' && ptr->content[ptr->index] == '\n')
		ptr->index++;
	while (ptr->content[ptr->index] && ptr->content[ptr->index] != '\n')
	{
		i++;
		ptr->index++;
	}
	*line = (char *)malloc(i);
	*line = ft_strncpy(*line, ptr->content + ptr->index - i, i);
	if (ptr->index + 1 == ptr->nb || ptr->content[0] == '\0')
		return (0);
	return (1);
}
