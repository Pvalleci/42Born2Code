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
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>////////////////////////////

typedef struct	s_list_ls
{
	char				*name;
	struct s_list_ls	*next;
}				t_list_ls;


int				ft_check_is_rep(char *name);
char			*ft_get_option(int ac, char **av);
char			**ft_get_path(int ac, char **av);
char			**ft_to_tab(t_list_ls *list, char *option);
t_list_ls		*ft_create_list(char *name);
void			ft_sort_tab(char *name, char *option, char **tab);
void			ft_display(char *name, char **tab, char *option);
void			ft_free_tab(char **tab);
void			ft_free_list(t_list_ls *list);
void			ft_ls(char *name, char *option);
void			ft_ls_recusive(t_list_ls *list, char *name, char *option);








void		ft_aff_list(t_list_ls *list);///////////////

#endif
