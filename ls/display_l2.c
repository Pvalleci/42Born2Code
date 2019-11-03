/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:59:28 by juaalvar          #+#    #+#             */
/*   Updated: 2019/05/11 16:59:30 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"



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
	write(1, "  ", 2);
}

int		ft_print_links_ID(struct stat stats, int size)
{
	struct group 	*grp;
	int				i;
	int				links;

	i = 1;
	grp = getgrgid(stats.st_gid);
	links = size - ft_count_len_int(stats.st_nlink);
	while (links > 0)
	{
		ft_putchar(' ');
		links--;
	// }
	// printf("%d %s  %s  ", stats.st_nlink,
	// 	pws->pw_name, grp->gr_name);

	printf("%d\n", stats.st_nlink);
	fflush(stdout);
	return (1);
}

int		ft_print_pws(struct stat stats)
{
	struct passwd 	*pws;
	int				i;
	int 			space;

	if (space = )
	i = 0;
	pws = getpwuid(stats.st_uid);

}

int		ft_size(struct stat stats, int size_size)
{
	int			size;
	int			space;

	space = size_size - ft_count_len_int(stats.st_size);
	size = stats.st_size;
	if (size == 0)
		space--;
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
	printf("%d ", size);
	fflush(stdout);
	return(1);
}

int			ft_date(struct stat stats)
{
	(void)stats;
	// printf("|..|");
	// fflush(stdout);
	char *months[] = { "jan", "fev", "mar",
				"apr", "may", "jun", "jul",
				"aug", "sep", "oct",
				"nov", "dec" };
	// char *dest;
	struct tm *time;

	// dest = ctime(&stats.st_mtime);
	time = gmtime(&stats.st_mtime);
	if (time->tm_mday < 10)
		ft_putchar(' ');
	printf("%d %s ", time->tm_mday, months[time->tm_mon]);
	fflush(stdout);
	// ft_putchar(' ');
	if ((time->tm_hour + 1) < 10)
		ft_putchar('0');
	ft_putnbr(time->tm_hour + 1);
	ft_putchar(':');
	if (time->tm_min < 10)
		ft_putchar('0');
	ft_putnbr(time->tm_min);
	// ft_putchar(' ');
	// tmp = ctime(&stats.st_mtime);
	// write(1, tmp, 16);

	return (1);	
}

void		ft_l_brain(char *name, char **tab, char *option)
{
	int			i;
	int 		link_size;
	int			size_size;
	char		*tmp;
	struct stat stats;

	i = 0;
	if ((link_size = ft_link_size(name, tab)) == 0 || (size_size = ft_big_size(tab, name)) == 0 || )
		return ;
	while (tab[i])
	{
		if ((ft_strchr(option, 'a') == NULL && tab[i][0] != '.') || ft_strchr(option, 'a') != NULL)
		{
			tmp = ft_strjoin(name, "/");
			tmp = ft_strjoin(tmp, tab[i]);//leaks
			if (stat(tmp, &stats) < 0)
				return ;
			ft_print_right(stats);
			ft_print_links_ID(stats, link_size);
			ft_size(stats, size_size);
			ft_date(stats);
			printf(" %s", tab[i]);
			printf("\n");
		}
		i++;
	}
}

void		ft_display_l(char *path, char **file_tab, char *option)
{

	// printf("ft_display_all----------------\n");
	// printf("Repertoires: -----------------\n");
	// // ft_print_table(tab1);
	// printf("%s\n", name);
	// printf("-------------------------------\n");
	// printf("ce sur quoi il faut faire -l : \n");
	// ft_print_table(tab);
	// printf("-------------------------------\n");


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
