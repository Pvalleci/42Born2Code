/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:16:22 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/28 13:57:39 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = (char)src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return ((void*)dest);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list) * 1)))
		return (0);
	newlist->content = ((void*)malloc(ft_strlen(content)));
	if (newlist->content == NULL)
		return (0);
	ft_memcpy(newlist->content, content, ft_strlen(content));
	newlist->content_size = content_size;
	newlist->next = NULL;
	return (newlist);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(str) * (size + 1))))
		return (NULL);
	while (s1[i])
		str[j++] = (char)s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = (char)s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_getfile(const int fd)
{
	char *s = NULL;
	int nblu;
	char buf[BUFF_SIZE + 1];

	nblu = 0;
	if (!s)
	{
		nblu = read(fd, buf, BUFF_SIZE);
		buf[nblu] = '\0';
		if (!(s = (char *)malloc(nblu)))
			return (NULL);
		s = ft_strncpy(s, buf, nblu);
	}
	while ((nblu = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nblu] = '\0';
		s = ft_strjoin(s, buf);
	}
	printf("file : %s\n", s);
	return (s);
}

void	ft_affiche_liste(t_list *maillon)
{
	printf("maillon->content_size : %d\n", (int)maillon->content_size);
	if (maillon->next != NULL)
	{
		ft_affiche_liste(maillon->next);
	}
}

char	*ft_clean_content(char *s, int i)
{
	char *tmp;
	int j;

	j = 0;
	i++;
	while (s[i + j] != '\0')
		j++;
	tmp = (char *)malloc(j);
	tmp = ft_strncpy(tmp, s + i, j);
	free(s);
	s = NULL;
	return (tmp);
}

t_list	*ft_parcour_list(t_list *maillon, const int fd)
{
	if (maillon->content_size != (size_t)fd && maillon->next != NULL)
		return (ft_parcour_list(maillon->next, fd));
	else if (maillon->content_size != (size_t)fd && maillon->next == NULL)
	{
		printf("LE MAILLON N'A PAS ETE TROUVE\nCREATION D UN NOUVEAU MAILLON\n");
		maillon->next = ft_lstnew(ft_getfile(fd), fd);
		return (maillon->next);
	}
	printf("LE MAILLON EXISTE\n");
	return (maillon);
}

int		get_next_line(const int fd, char **line)
{
	printf("\n--------------------------------\n\n");
	static t_list *maillon = NULL;
	t_list *ptr;
	int		i;

	i = 0;
	if (!maillon)
	{
		maillon = ft_lstnew(ft_getfile(fd), fd);
		ptr = maillon;		
	}
	else	
		ptr = ft_parcour_list(maillon, fd);
	while (ptr->content[i] != '\n' && ptr->content[i])
		i++;
	*line = (char *)malloc(ft_strlen(ptr->content));
	*line = ft_strncpy(*line, ptr->content, i);
	printf("line : %s\n", *line);
	ptr->content = ft_clean_content(ptr->content, i);
	printf("reste : %s", ptr->content);
	printf("\n--------------FIN--------------\n\n");
	return (0);
}

int		main(void)
{
	int fd1;
	int fd2;
	char *line;

	fd1 = open("texte1", O_RDONLY);
	fd2 = open("texte2", O_RDONLY);
	get_next_line(fd1, &line);
	get_next_line(fd2, &line);
	get_next_line(fd1, &line);
	close(fd1);
	close(fd2);
	return 0;
}

