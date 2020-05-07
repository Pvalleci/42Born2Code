/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:40:33 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/16 19:40:35 by pvalleci         ###   ########.fr       */
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
	//(stats.st_mode & S_IFLNK) ? ft_putchar('@') : ft_putchar(' ');
	write(1, " ", 2);
}

// void ft_take_size(char *rep_tab)
// {
// 	char 	**contenu;
// 	int 	i;
// 	struct	stat stats;

// 	i = 0;
// 	contenu = ft_get_intra_rep(tab);
// 	ft_print_table(contenu);
// 	while (contenu[i])
// 	{
// 		if (stat(contenu[i], &stats) != 0)
// 			return ;
// 		ft_print_right(stats);
// 		printf("\n");
// 		i++;
// 	}
// 	// struct stat stats;

// 	// if (stat(tab, &stats) != 0)
// 	// 	return ;

	
// }

// int		ft_print_links_ID(struct stat stats, t_size size)
// {
// 	int				i;
// 	int				links;
// 	struct group 	*grp;
// 	struct passwd 	*pws;

// 	i = 1;
// 	grp = getgrgid(stats.st_gid);
// 	pws = getpwuid(stats.st_uid);
// 	links = size.link_size - ft_count_len_int(stats.st_nlink);
// 	while (links > 0)
// 	{
// 		ft_putchar(' ');
// 		links--;
// 	}
// 	printf("%d ", stats.st_nlink);
// 	fflush(stdout);
// 	ft_putstr(pws->pw_name);
// 	links = size.pws_size - ft_strlen(pws->pw_name);
// 	while (links > 0)
// 	{
// 		ft_putchar(' ');
// 		links--;
// 	}
// 	ft_putstr("  ");
// 	ft_putstr(grp->gr_name);
// 	links = size.grp_size - ft_strlen(grp->gr_name);
// 	while (links > 0)
// 	{
// 		ft_putchar(' ');
// 		links--;
// 	}
// 	ft_putstr("  |");
// 	return (1);
// }

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

	printf("%s ", months[time->tm_mon]);
	if (time->tm_mday < 10)
		printf(" ");
	printf("%d ", time->tm_mday );
	fflush(stdout);
	// printf(' ');
	if ((time->tm_hour + 1) < 10)
		printf("0");
	printf("%d", (time->tm_hour + 1));
	printf(":");
	if (time->tm_min < 10)
		printf("0");
	printf("%d", (time->tm_min));
	// printf(' ');
	// tmp = ctime(&stats.st_mtime);
	// write(1, tmp, 16);

	return (1);	
}

void	ft_brain(struct stat stats, char *name, char *path, t_size size, char *option)
{
	int space;
	struct passwd 	*pws;
	struct group 	*grp;
	char	buf[256];
	int len;

	pws = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	if ((ft_strchr(option, 'a') == NULL) && name[0] == '.')
		return ;

	space = size.nblink_size - ft_nbrlen(stats.st_nlink);
	ft_print_right(stats);
	while (space-- > 0)
		printf(" ");
	printf(" %d ", stats.st_nlink);
	space = size.pws_size - ft_strlen(pws->pw_name);
	while (space-- > 0)
		printf(" ");
	printf("%s  ", pws->pw_name);
	space = size.grp_size - ft_strlen(grp->gr_name);
	while (space-- > 0)
		printf(" ");
	printf("%s  ", grp->gr_name);
	space = size.size_max - ft_nbrlen(stats.st_size);
	while (space-- > 0)
		printf(" ");
	printf("%lld ", stats.st_size);

	ft_date(stats);

	printf(" %s", name);
	if (S_ISLNK(stats.st_mode))
	{
		len = readlink(path, buf, sizeof(buf));
		buf[len] = '\0';
		printf(" -> %s", buf);
	}
	printf("\n");
	//printf("NAME = %s, PATH = %s\n", name, path);
	//printf("\n");
}

t_size ft_start_struct_size(t_size size, int i)
{
	size.nblink_size = i;
	size.pws_size = i;
	size.grp_size = i;
	size.size_max = i;
	return (size);
}

t_size  ft_take_size(struct stat stats, t_size size)
{
	struct group 	*grp;
	struct passwd 	*pws;

	pws = getpwuid(stats.st_uid);
	if(pws == NULL)
	{
		printf("NULL\n");
		perror("getpwuid");
		// pws = getpwnam("/Applications/Adobe/Adobe Acrobat X Pro/Acrobat Distiller.app/Contents/Frameworks/AMTLibWrapper.framework/Resources");
		// if (pws == NULL)
		// {
		// 	perror("getpwnam");
		// 	printf("NULL aussi\n");
		// }
	}

	grp = getgrgid(stats.st_gid);
	if (size.nblink_size < ft_nbrlen(stats.st_nlink))
		size.nblink_size = ft_nbrlen(stats.st_nlink);
	if (size.pws_size < ft_strlen(pws->pw_name))
		size.pws_size = ft_strlen(pws->pw_name);
	if (size.grp_size < ft_strlen(grp->gr_name))
		size.grp_size = ft_strlen(grp->gr_name);
	if (size.size_max < ft_nbrlen(stats.st_size))
		size.size_max = ft_nbrlen(stats.st_size);
	return (size);
}

t_size	ft_print_total(char *tab, char **contenu, int i, char *option)
{
	int 	total;
	char 	*path;
	struct	stat stats;
	t_size	size;
	
	total = 0;
	size = ft_start_struct_size(size, 0);
	//ft_print_table(contenu);
	while (contenu[i])
	{
		if ((ft_strchr(option, 'a') == NULL) && contenu[i][0] == '.')
			i++;
		else
		{
			path = ft_clean_path(tab, contenu[i]);
			if (lstat(path, &stats) != 0)
				return (size);
			size = ft_take_size(stats, size);
			total = total + stats.st_blocks;
			i++;
			ft_strdel(&path);
		}
	}
	printf("total %d\n", total);
	return (size);
}

t_size 	ft_just_take_size(char **contenu)
{
	t_size size;
	struct stat stats;
	int i;

	if (contenu[1] == NULL)
		return (ft_start_struct_size(size, 1));
	size = ft_start_struct_size(size, 0);
	i = 0;
	while (contenu[i])
	{
		if(lstat(contenu[i], &stats) != 0)
			return (size);
		size = ft_take_size(stats, size);
		i++;
	}
	return (size);
}

char 	**ft_get_rep_tab(char **tab)
{
	int 	i;
	int 	j;
	int 	nb;
	char	**rep_tab;
	struct stat sb;

	nb = ft_count_rep(tab);
	if (!(rep_tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (stat(tab[i], &sb) != 0)
			return (NULL);
		if (S_ISDIR(sb.st_mode))
		{
			if (!(rep_tab[j] = ft_strdup(tab[i])))
				return (NULL);
			j++;
		}
		i++;
	}
	rep_tab[j] = NULL;
	return (rep_tab);
}

int		ft_opt_long(char **tab, char *option, int total)
{
	// printf("coucou\n");
	char 	**contenu;
	char	**rep_tab;
	char	**file_tab;
	int 	i;
	int		j;
	struct	stat stats;
	char	*path;
	static int n = 0;
	t_size	size;

	i = 0;
	j = 0;
	rep_tab = ft_get_rep_tab(tab);
	file_tab = ft_create_file_tab(tab);
	while (file_tab && file_tab[j])
	{
		n = 1;
		size = ft_just_take_size(file_tab);
		if (lstat(file_tab[j], &stats) != 0)
			return (0);
		ft_brain(stats, file_tab[j], file_tab[j], size, option);
		j++;
	}
	j = 0;
	if (file_tab && rep_tab)
		printf("\n");
	if (ft_len_tab(rep_tab) > 1)
		n = 1;
	while (rep_tab && rep_tab[j])
	{
		if (n == 1)
			printf("%s:\n", rep_tab[j]);
		contenu = ft_get_intra_rep(rep_tab[j]);
		ft_sort(contenu, rep_tab[j], option);
		size = ft_print_total(rep_tab[j], contenu, 0, option);
		//ft_sort(contenu, rep_tab[j], option);
		while (contenu[i])
		{
			path = ft_clean_path(rep_tab[j], contenu[i]);
			if (lstat(path, &stats) != 0)
				return (0);
			ft_brain(stats, contenu[i], path, size, option);
			i++;
			ft_strdel(&path);
		}
		ft_free_tab(contenu);
		j++;
		i = 0;
		total = 0;
		n = 1;
		if (rep_tab[j])
			printf("\n");
	}
	if (rep_tab)
		ft_free_tab(rep_tab);
	if (file_tab)
	{
		// printf("file : %p\n", file_tab);
		ft_free_tab(file_tab);
	}
	return (0);
}

