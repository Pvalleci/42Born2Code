/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:14:10 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/16 18:14:11 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newmaillon;

	if (lst->next != NULL)
	{
		newmaillon = ft_lstnew(lst->content, lst->content_size);
		newmaillon = f(lst);
		newmaillon->next = ft_lstmap(lst->next, f);
	}
	if (lst->next == NULL)
	{
		newmaillon = ft_lstnew(lst->content, lst->content_size);
		newmaillon = f(lst);
		newmaillon->next = NULL;
	}
	return (newmaillon);
}
