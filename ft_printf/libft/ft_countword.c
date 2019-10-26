/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:46:03 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/19 11:36:43 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char *str, char lettre)
{
	size_t	i;
	size_t	y;

	if (!str || !lettre)
		return (0);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (y == 0 && str[i] != lettre)
			y++;
		else if (str[i] != lettre && str[i - 1] == lettre)
			y++;
		i++;
	}
	return (y);
}
