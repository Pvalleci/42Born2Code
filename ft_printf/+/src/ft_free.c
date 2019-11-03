/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 06:54:21 by pvalleci          #+#    #+#             */
/*   Updated: 2019/10/29 06:54:26 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_list(t_param *list)
{
	if (list->next != NULL)
		ft_free_list(list->next);
	free(list->result);
	free(list->flag);
	free(list);
}
