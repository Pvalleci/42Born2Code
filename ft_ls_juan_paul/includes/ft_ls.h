/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:28:19 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 16:28:22 by pvalleci         ###   ########.fr       */
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
# include <stdio.h>////////////////////////////

typedef struct	s_list_ls
{
	char				*name;
	struct s_list_ls	*next;
}				t_list_ls;


int				ft_check_is_rep(char *name);
int				ft_verif_option(char *option);
int				ft_count_len_int(int nb);
int				ft_len_tab(char **tab);
int				ft_link_size(char *name, char **tab);
char			**ft_pars_folders(int argc, char **argv);
char			**ft_valid_folders(char **folders, int i, int j);
char			**ft_verif_folders(char **folders);
char			*ft_pars_option(int argc, char **argv);
char			**ft_to_tab(t_list_ls *list, char *option);
char			**ft_copy_tab(char **tab);
t_list_ls		*ft_create_list(char *name);
void			ft_sort_tab(char *name, char *option, char **tab);
void			ft_display(char *name, char **tab, char *option, int nb_path);
void			ft_free_tab(char **tab);
void			ft_free_list(t_list_ls *list);
void			ft_ls(char *name, char *option, int nb_path);
void			ft_ls_recusive(char **tab, char *name, char *option, int nb_path);
void			ft_print_l(char *name, char **tab);
void			ft_display_ioctl(char *name, char **tab);







void		ft_aff_list(t_list_ls *list);///////////////

#endif
