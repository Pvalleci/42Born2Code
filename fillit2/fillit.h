/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:46:40 by pvalleci          #+#    #+#             */
/*   Updated: 2019/01/11 16:49:20 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define S_TETRI

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

typedef struct		s_tetri
{
	char			**tab;
	int				put;
	struct s_tetri 	*next;
}					t_tetri;

int			get_next_line(const int fd, char **line);
int			ft_check_tetriminos(char *str);
void		ft_affiche_list(t_tetri	*list);
t_list		*ft_correct_shift(t_list *list);

#endif
