
#include "ft_ls.h"

void		ft_print_right(struct stat stats)
{
	S_ISDIR(stats.st_mode) ? ft_putchar('d') : ft_putchar('-');
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
	struct passwd 	*pws;
	struct group 	*grp;
	int				i;
	int				links;

	i = 1;
	pws = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	links = size - ft_count_len_int(stats.st_nlink);
	while (links > 0)
	{
		ft_putchar(' ');
		links--;
	}
	printf("%d %s  %s  ", stats.st_nlink,
		pws->pw_name, grp->gr_name);
	return (1);
}

void		ft_l_brain(char *name, char **tab)
{
	int			i;
	int 		link_size;
	char		*tmp;
	struct stat stats;

	i = 0;
	if ((link_size = ft_link_size(name, tab)) == 0)
		return ;
	while (tab[i])
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, tab[i]);//leaks
		if (stat(tmp, &stats) < 0)
			return ;
		ft_print_right(stats);
		ft_print_links_ID(stats, link_size);
		printf("\n");
		i++;
	}
}

void		ft_print_l(char *name, char **tab)
{
	int		i;
	int		total;
	struct stat stats;

	i = 0;
	total = 0;
	while (tab[i] != NULL)
	{

		if (stat(tab[i], &stats) > 0)
			return ;
		total = total + stats.st_blocks;
		i++;
	}
	printf("total %d\n", total);
	ft_l_brain(name, tab);
}