/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:14:22 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/04 15:41:34 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newl;

	if (!lst || !f)
		return (NULL);
	if (lst->next != NULL)
	{
		newl = ft_lstnew(lst->content, lst->content_size);
		newl = f(lst);
		newl->next = ft_lstmap(lst->next, f);
	}
	if (lst->next == NULL)
	{
		newl = ft_lstnew(lst->content, lst->content_size);
		newl = f(lst);
		newl->next = NULL;
	}
	return (newl);
}
