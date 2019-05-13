 
#include "ft_ls.h"

char		**ft_get_intra_rep(char *rep)
{
	char			**intra_rep;
	DIR				*opdir;
	struct dirent	*rdir;
	int 			len;

	len = 0;	
	if (!(opdir = opendir((const char *)rep)))
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
		len++;
	closedir(opdir);
	if (!(intra_rep = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	if (!(opdir = opendir((const char *)rep)))		
		return (NULL);
	while ((rdir = readdir(opdir)) != NULL)
	{
		intra_rep[len] = ft_strdup(rdir->d_name);
		len++;
	}
	intra_rep[len] = NULL;
	closedir(opdir);
	return (intra_rep);
}



void		ft_display(char *path, char **file_tab, char *option)
{
	ft_sort(file_tab, path, option);
	// if (ft_strchr(option, 'l') != NULL)
	// 	ft_display_all(path ,file_tab, option);
	ft_display_ioctl(file_tab, option);
	
}

void		ft_display_rep(char *path, char *option, int i)
{
	char		**intra_rep;

	intra_rep = NULL;
	if (i > 1 && path)
		printf("%s:\n", path);
	if (path)
		intra_rep = ft_get_intra_rep(path);
	if (intra_rep)
	{
		if (ft_len_tab(intra_rep) == 2 && ft_strchr(option, 'a') == NULL)
		{
			ft_free_tab(intra_rep);
			return ;
		}
		ft_display(path, intra_rep, option);
		// printf("t5456465465to\n");
		// write(1, "\n", 1);
		ft_free_tab(intra_rep);
	}
	else
		intra_rep = NULL;
}