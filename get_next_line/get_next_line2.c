/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:19:42 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/23 17:14:32 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE 32

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	ft_check_line(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' || s[i])
		i++;
	if (s[i] == '\n')
		return (i);
	return (0);
}

void	ft_clean_static(char **s, int n)
{
	int i;
	char	*tmp;

	while (*s[i])
		i++;
	tmp = malloc(i);
	i = 0;
	while(*s[i])
	{
		tmp[i] = *s[i];
		i++;
	}
	tmp[i] = 0;
	*s = malloc(i);
	ft_memcpy(*s, tmp, i);
}

int	get_next_line(int fd, char **line)
{
	static char *s = NULL;
	int nblu;
	int n;
	char	buf[BUFF_SIZE + 1];

	nblu = 0;
		if (!s)
		{
			s = malloc(BUFF_SIZE + 1);
			nblu = read(fd, s, BUFF_SIZE);
			printf("nblu: %d\n", nblu);
			s[nblu] = 0;	
			printf("%s\n", s);
			printf("OK");
		}
			n = ft_check_line(s);
			printf("%d\n", n);
			if (n > 0)//il y a un '\n'
			{
				ft_memcpy(*line, s, n);
				ft_clean_static(&s+n , n);
				return (1);
			}
			else//il n  y a pas de \n
			{
			//	realloc la s
				;
				//strjoin de s et buf
			}
	return (0);
}


int	main(void)
{
	int	fd;
	char *line;

	fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
