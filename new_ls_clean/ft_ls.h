

#ifndef FT_LS_H

#define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <sys/ioctl.h>
# include <stdio.h>


typedef struct	s_list_ls
{
	char				*name;
	struct s_list_ls	*next;
}				t_list_ls;

int			ft_verif_option(char *option);
char		*ft_pars_option(int argc, char **argv);
char		**ft_get_intra_rep(char *rep);
char		**ft_pars_folders(int argc, char **argv);
char		**ft_verif_folders(char **folders);
char		**ft_clean_tab(char **tab, char *option);
t_list_ls	*ft_create_list(char **path);
void		ft_sort_tab(char *option, char **tab);
char		**ft_copy_tab(char **tab);
int			ft_len_tab(char **tab);
int			ft_is_not_directory(char *str);
void		ft_display(char **tab, char *option, int i);
void		ft_display_ioctl(char **tab, char *option);
void		ft_ls(char **path, char *option, int i);
void		ft_recursive_ls(char **path, char *option);
void		ft_aff_tab(char **tab);
void		ft_free_tab(char **tab);
void		ft_free_list(t_list_ls *list);

#endif