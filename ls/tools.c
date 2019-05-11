
#include "ft_ls.h"


void			ft_input_tab_ioctl(char **io_tab, char **tab, int buf, int nb_col)
{
	char	tmp_buf[buf + 1];
	int 	i;
	int 	j;
	int 	io;

	i = 0;
	j = 0; 
	io = 0;
	while (tab[i])
	{	
		if (io_tab[io] == NULL)
			io = 0;
		ft_strcpy(tmp_buf, tab[i]);
		j = ft_strlen(tab[i]);		
		while (j < buf + 1)
		{
			tmp_buf[j] = ' ';
			j++;
		}
		j--;
		tmp_buf[j] = '\0';
		io_tab[io] = ft_strcat(io_tab[io], tmp_buf);
		i++;
		io++;
	}
}

char			**ft_buf_tab(char **tab, int nb_column, int	len_line, int len_buf)	
{
	char		**ioctl_tab;
	int 		nb_line;
	int			i;

	i = 0;
	nb_line = ft_len_tab(tab) / nb_column;
	while (nb_line * nb_column < ft_len_tab(tab))
		nb_line++;
	if (!(ioctl_tab = (char **)malloc(sizeof(char *) * (nb_line + 1))))
		return (NULL);
	while (i < nb_line)
	{
		ioctl_tab[i] = ft_strnew(len_line);
		i++;
	}
	ioctl_tab[i] = NULL;
	i = 0;
	ft_input_tab_ioctl(ioctl_tab , tab, len_buf, nb_column);
	ft_free_tab(tab);
	return (ioctl_tab);
}

char			**ft_clean_tab(char **tab, char *option)
{
	char	**tmp_tab;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ft_strchr(option, 'a') != NULL)
		return (tab);
	while (tab[i])
	{
		if (tab[i][0] != '.')
			len++;
		i++;
	}
	if (!(tmp_tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '.')
			i++;
		else
		{
			tmp_tab[len] = ft_strdup(tab[i]);
			len++;
			i++;
		}
	}
	tmp_tab[len] = NULL;
	ft_free_tab(tab);
	return (tmp_tab);
}

void			ft_aff_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}


char				**ft_copy_tab(char **tab)
{
	char			**tmp_tab;
	int				i;

	i = 0;
	if (!tab)
		return (NULL);
	if (!(tmp_tab = (char **)malloc(sizeof(char *) * (ft_len_tab(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		tmp_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp_tab[i] = NULL;
	return (tmp_tab);
}
