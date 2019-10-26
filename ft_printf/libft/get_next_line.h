/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:14:34 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/03 16:18:47 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

typedef struct		s_chain
{
	int					fd;
	int					index;
	int					endfile;
	char				*file;
	struct s_chain		*next;
}					t_chain;

int					get_next_line(const int fd, char **line);

#endif
