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

void		ft_display_ioctl(char **file_tab, char *option);
char			**ft_buf_tab(char **tab, int nb_column, int	len_line, int len_max);
int				ft_len_tab(char **tab);
int		ft_is_not_directory(char *str);
void			ft_sort_by_ascii(char **tab);
void		ft_free_tab(char **tab);
char		*ft_pars_option(int argc, char **argv);
int			ft_verif_option(char *option);
char		**ft_pars_folders(int argc, char **argv);
char		**ft_verif_folders(char **folders);
void		ft_separate_path(char **path, char ***rep_tab, char ***file_tab);
void		ft_display_rep(char *path, char *option, int i);
void		ft_display(char *path, char **file_tab, char *option, int i);
char		**ft_get_intra_rep(char *rep);
void		ft_ls(char **path, char *option, int i);
int			ft_get_len_max(char **tab);
char				**ft_copy_tab(char **tab);
char			**ft_clean_tab(char **tab, char *option);

#endif