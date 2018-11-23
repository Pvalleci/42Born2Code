/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:53:04 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/21 11:23:37 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 32
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	l;
	char	*str;

	i = 0;
	l = (char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == l)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

// char				*ft_strjoin(const char *s1, const char *s2)
// {
// 	const size_t 	l1 = strlen(s1);
// 	const size_t 	l2 = strlen(s2);
// 	char			*ptr;

// 	if (!(ptr = malloc(l1 + l2 + 1)))
// 		return (ptr);
// 	while (*s1)
// 		*ptr++ = *s1++;
// 	while (*s2)
// 		*ptr++ = *s2++;
// 	*ptr = 0;
// 	return (ptr - (l1 + l2));
// }

// #include <string.h>
// char	*ft_getfile(const int fd)
// {
// 	char buf[BUFF_SIZE];
// 	ssize_t	nblu;
// 	char	*ptr;
// 	char	*tmp;
// 	char	*joe;

// 	tmp = NULL;
// 	while ((nblu = read(fd, buf, BUFF_SIZE)) > 0)
// 	{
// 		ptr = malloc(nblu + 1);
// 		ptr[nblu] = 0;
// 		ft_memcpy(ptr, buf, nblu);
// 		if (!tmp)
// 			tmp = ptr;
// 		else
// 		{
// 			joe = ptr;
// 			ptr = ft_strjoin(tmp, ptr);
// 			free(tmp);
// 			free(joe);
// 			tmp = ptr;
// 		}
// 	}
// 	return (ptr);
// }

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (n > 0)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

char	*ft_realloc(char	*s, size_t n)
{
	char *new;
	int	i;

	i = 0;
	new = malloc(n);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0'; 
	return (new);
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

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_next_line(const int fd, char **line)
{
	char		tmp[BUFF_SIZE + 1];
	ssize_t		ret;
	static char	*dest;
	int			j;
	int			i;

	if (!dest)//si dest n a  pas ete malloc
		dest = malloc(BUFF_SIZE + 1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)//tant qu'il y a lire
	{
		tmp[BUFF_SIZE] = '\0';
		printf("%s\n", tmp);
		if (ft_strchr(tmp, '\n') == NULL)//cas ou il n y a pas de \n ds la lecture
		{
			ft_strcat(dest, tmp);
			ft_bzero(tmp, BUFF_SIZE + 1);
		}
		else//cas ou il y a un \n ds la lecture
		{
			i = 0;
			j = 0;
			while (tmp[i] != '\n')
				i++;
			ft_memcpy(*line, tmp, i);
			while (tmp[i])
				dest[j++] = tmp[i++];
			ft_bzero(tmp, BUFF_SIZE + 1);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	printf("%s\n", line);
	argc = 1;
	return (0);
}
