/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:31:22 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:31:25 by pvalleci         ###   ########.fr       */
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
