/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 02:00:16 by pvalleci          #+#    #+#             */
/*   Updated: 2019/05/14 17:15:46 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct 		s_opt_l
{
	int 	*nb_blocs;
	char 	type;
	char 	*rights;
	int 	*nb_links;
	char 	*name_owner;
	char 	*groupe;
	char 	*taille;
	char 	*date;
	char 	*name;

}					t_opts;

typedef struct		s_size
{
	int 	nblink_size;
	int		pws_size;
	int		grp_size;
	int		size_max;
	char 	*option;
}					t_size;

int			ft_len_tab(char **tab);
int			ft_is_not_directory(char *str);
int			ft_verif_option(char *option);
int 		ft_only_char(char *str, char c);
int			ft_nbrlen(int nb);
int 		ft_count_rep(char **tab);
void		ft_sort_by_ascii(char **tab);
void		ft_free_tab(char **tab);
char		*ft_pars_option(int argc, char **argv);
char		**ft_pars_folders(int argc, char **argv);
char		**ft_verif_folders(char **folders);
char		**ft_buf_tab(char **tab, int nb_column, int	len_line, int len_max);
void		ft_separate_path(char **path, char ***rep_tab, char ***file_tab);
void		ft_display_rep(char *path, char *option, int i);
void		ft_display(char *path, char **file_tab, char *option);
void		ft_display_ioctl(char **file_tab, char *option);
char		**ft_get_intra_rep(char *rep);
void		ft_ls(char **path, char *option, int i);
int			ft_get_len_max(char **tab);
char		**ft_copy_tab(char **tab);
char		**ft_clean_tab(char **tab, char *option);
int			ft_filter_recursive(char *option, char **intra_rep);
int			ft_opt_long(char **tab, char *opt);
char		*ft_clean_path(char *path, char *rep);
int 		ft_check_space(char **rep_tab, int j, char *option);
void		ft_sort(char **tab, char *path, char *option);
void		ft_quicksort(char **tab, int start, int end, void *f, char *path);
void		ft_sort_long(char **tab, char *option);
char		**ft_create_rep_tab(char **tab);
char		**ft_create_file_tab(char **tab);
#endif
