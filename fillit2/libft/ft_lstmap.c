/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:30:39 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/22 20:30:43 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newmaillon;

	if (!(lst && f))
		return (0);
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
