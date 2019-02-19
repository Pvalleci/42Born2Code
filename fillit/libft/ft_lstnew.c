/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:15:47 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/22 17:15:52 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list) * 1)))
		return (0);
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
		return (newlist);
	}
	else
	{
		if (!(newlist->content = ((void*)malloc(sizeof(void) * content_size))))
			return (NULL);
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
		newlist->next = NULL;
		return (newlist);
	}
}
