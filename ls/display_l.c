/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 22:08:09 by juaalvar          #+#    #+#             */
/*   Updated: 2019/05/20 22:08:11 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* ---------------------------------------------------------------------*/

int			ft_grp_size(char **tab, char *name)
{
	int				i;
	int				size;
	char			*tmp;
	struct group 	*grp;
	struct stat 	stats;

	i = 0;
	size = 0;
	while (tab[i])
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, tab[i]);//leaks
		if (stat(tmp, &stats) < 0)
			return (-1);
		grp = getgrgid(stats.st_gid);
		if (ft_strlen(grp->gr_name) > size)
			size = ft_strlen(grp->gr_name);
		i++;
	}
	return (size);
}

/* ---------------------------------------------------------------------*/

void		ft_print_right(struct stat stats)
{
	S_ISDIR(stats.st_mode) ? ft_putchar('d') : 0;
	S_ISREG (stats.st_mode) ? ft_putchar('-') : 0;
	S_ISBLK (stats.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR (stats.st_mode) ? ft_putchar('c') : 0;
	S_ISFIFO (stats.st_mode) ? ft_putchar('p') : 0;
	S_ISLNK (stats.st_mode) ? ft_putchar('l') : 0;
	S_ISSOCK (stats.st_mode) ? ft_putchar('s') : 0;
	(stats.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(stats.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(stats.st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(stats.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(stats.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(stats.st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(stats.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(stats.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(stats.st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	// (stats.st_mode & S_IFLNK) ? ft_putchar('@') : ft_putchar(' ');
	write(1, " ", 2);
}

int		ft_print_links_ID(struct stat stats, t_size size)
{
	int				i;
	int				links;
	struct group 	*grp;
	struct passwd 	*pws;

	i = 1;
	grp = getgrgid(stats.st_gid);
	pws = getpwuid(stats.st_uid);
	links = size.link_size - ft_count_len_int(stats.st_nlink);
	while (links > 0)
	{
		ft_putchar(' ');
		links--;
	}
	printf("%d ", stats.st_nlink);
	fflush(stdout);
	ft_putstr(pws->pw_name);
	links = size.pws_size - ft_strlen(pws->pw_name);
	while (links > 0)
	{
		ft_putchar(' ');
		links--;
	}
	ft_putstr("  ");
	ft_putstr(grp->gr_name);
	links = size.grp_size - ft_strlen(grp->gr_name);
	while (links > 0)
	{
		ft_putchar(' ');
		links--;
	}
	ft_putstr("  |");
	return (1);
}


t_size		ft_get_size(char *name, char **tab)
{
	t_size size;

	if ((size.link_size = ft_link_size(name, tab)) == 0 || (size.big_size = ft_big_size(tab, name)) == 0 ||
	(size.pws_size = ft_pws_size(tab, name)) == -1 || (size.grp_size = ft_grp_size(tab, name)) == -1) //|| (size.pws_size = ft_pws_size(tab, name)) == 0
		return (size);

	return (size);	
}


void		ft_l_brain(char *name, char **tab, char *option)
{
	int			i;
	char		*tmp;
	struct stat	stats;
	t_size		size;

	i = 0;
	size = ft_get_size(name, tab);
	while (tab[i])
	{
		if ((ft_strchr(option, 'a') == NULL && tab[i][0] != '.') || ft_strchr(option, 'a') != NULL)
		{
			tmp = ft_strjoin(name, "/");
			tmp = ft_strjoin(tmp, tab[i]);//leaks
			if (stat(tmp, &stats) < 0)
				return ;
			ft_print_right(stats);
			ft_print_links_ID(stats, size);
			// ft_size(stats, size);
			// ft_date(stats);
			// printf(" %s", tab[i]);
			printf("\n");
		}
		i++;
	}
}

void		ft_display_l(char *path, char **file_tab, char *option)
{
	int		i;
	int		total;
	struct stat stats;

	i = 0;
	total = 0;
	while (file_tab[i] != NULL)
	{

		if (stat(file_tab[i], &stats) > 0)
			return ;
		total = total + stats.st_blocks;
		i++;
	}
	printf("total %d\n", total);
	ft_l_brain(path, file_tab, option);
	printf("taille max = %d", ft_big_pwd(file_tab, path));
}
