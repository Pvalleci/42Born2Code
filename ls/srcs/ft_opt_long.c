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


void		ft_print_right(struct stat stats) // GOOD
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
	write(1, " ", 2);
}

char		**ft_create_tab_months(void) // GOOD
{
	char **tab;

	if (!(tab = malloc(sizeof(char *) * 13)))
		return (NULL);
	if (!((tab[0] = ft_strdup("Jan")) && (tab[1] = ft_strdup("Fev"))
		&& (tab[2] = ft_strdup("Mar")) && (tab[3] = ft_strdup("Apr"))
		&& (tab[4] = ft_strdup("May")) && (tab[5] = ft_strdup("Jun")) 
		&& (tab[6] = ft_strdup("Jul")) && (tab[7] = ft_strdup("Aug"))
		&& (tab[8] = ft_strdup("Sep")) && (tab[9] = ft_strdup("Oct"))
		&& (tab[10] = ft_strdup("Nov")) && (tab[11] = ft_strdup("Dec"))))
		return (NULL);
	tab[12] = NULL;
	return (tab);
}

int			ft_date(struct stat stats) // GOOD
{
	char **months;
	struct tm *time;


	if(!(months = ft_create_tab_months()))
		return (-1);
	time = gmtime(&stats.st_mtime);
	printf("%s ", months[time->tm_mon]);
	if (time->tm_mday < 10)
		printf(" ");
	printf("%d ", time->tm_mday );
	fflush(stdout);
	if ((time->tm_hour + 1) < 10)
		printf("0");
	printf("%d", (time->tm_hour + 1));
	printf(":");
	if (time->tm_min < 10)
		printf("0");
	printf("%d", (time->tm_min));
	return (1);	
}

void	ft_brain_2(struct stat stats, char *name, char *path, t_size size) // GOOD
{
	int		space;
	char	buf[256];
	int		len;
	struct group 	*grp;
	
	if ((ft_strchr(size.option, 'a') == NULL) && name[0] == '.')
		return ;
	grp = getgrgid(stats.st_gid);
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

}

void	ft_brain(struct stat stats, char *name, t_size size) // GOOD
{
	int space;
	struct passwd 	*pws;

	pws = getpwuid(stats.st_uid);
	if ((ft_strchr(size.option, 'a') == NULL) && name[0] == '.')
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
}

t_size ft_start_struct_size(t_size size, int i) // GOOD
{
	size.nblink_size = i;
	size.pws_size = i;
	size.grp_size = i;
	size.size_max = i;
	return (size);
}

t_size  ft_take_size(struct stat stats, t_size size, char *option) // GOOD
{
	struct group 	*grp;
	struct passwd 	*pws;

	pws = getpwuid(stats.st_uid);
	if(pws == NULL)
		printf("NULL\n");
	size.option = option;
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

t_size	ft_print_total(char *tab, char **contenu, int i, char *option) // GOOD
{
	int 	total;
	char 	*path;
	struct	stat stats;
	t_size	size;
	
	total = 0;
	size = ft_start_struct_size(size, 0);
	while (contenu[i])
	{
		if ((ft_strchr(option, 'a') == NULL) && contenu[i][0] == '.')
			i++;
		else
		{
			path = ft_clean_path(tab, contenu[i]);
			if (lstat(path, &stats) != 0)
				return (size);
			size = ft_take_size(stats, size, option);
			total = total + stats.st_blocks;
			i++;
			ft_strdel(&path);
		}
	}
	printf("total %d\n", total);
	return (size);
}

t_size 	ft_just_take_size(char **contenu, char *option) // GOOD
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
		size = ft_take_size(stats, size, option);
		i++;
	}
	return (size);
}

char 	**ft_get_rep_tab(char **tab) // GOOD
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

int		ft_long_p1(int n, int j, char *option, char ** tab)
{
	char	**rep_tab;
	char	**file_tab;
	t_size	size;
	struct	stat stats;


	rep_tab = ft_get_rep_tab(tab);
	file_tab = ft_create_file_tab(tab);
	while (file_tab && file_tab[j])
	{
		n = 1;
		size = ft_just_take_size(file_tab, option);
		if (lstat(file_tab[j], &stats) != 0)
			return (0);
		ft_brain(stats, file_tab[j], size);
		ft_brain_2(stats, file_tab[j], file_tab[j], size);
		j++;
	}
	if (file_tab && rep_tab)
		printf("\n");
	if (ft_len_tab(rep_tab) > 1)
		n = 1;
	return (n);
}

void	ft_start_brain(char *path, struct stat stats, char *contenu, t_size size)
{
	if (lstat(path, &stats) != 0)
		return ;
	ft_brain(stats, contenu, size);
	ft_brain_2(stats, contenu, path, size);
	ft_strdel(&path);
}

void	ft_long_p2(int n, int j, char **rep_tab, char *option)
{
	t_size	size;
	struct	stat stats;
	char 	**contenu;
	int 	i;
	char	*path;

	while (rep_tab && rep_tab[++j])
	{
		if (n == 1)
			printf("%s:\n", rep_tab[j]);
		contenu = ft_get_intra_rep(rep_tab[j]);
		ft_sort(contenu, rep_tab[j], option);
		size = ft_print_total(rep_tab[j], contenu, 0, option);
		i = 0;
		while (contenu[i])
		{
			path = ft_clean_path(rep_tab[j], contenu[i]);
			ft_start_brain(path, stats, contenu[i], size);
			i++;
		}
		ft_free_tab(contenu);
		n = 1;
		if (rep_tab[j + 1])
			printf("\n");
	}
}

int		ft_opt_long(char **tab, char *option)
{
	char	**rep_tab;
	char	**file_tab;
	struct	stat stats;
	static int n = 0;

	n = ft_long_p1(n, 0, option, tab);
	
	rep_tab = ft_get_rep_tab(tab);
	file_tab = ft_create_file_tab(tab);
	ft_long_p2(n, -1, rep_tab, option);
	n = 1;
	if (rep_tab)
		ft_free_tab(rep_tab);
	if (file_tab)
		ft_free_tab(file_tab);
	return (0);
}
