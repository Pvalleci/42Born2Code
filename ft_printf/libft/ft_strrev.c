/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:28:09 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/17 16:39:04 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		y;
	char	swap;

	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
		i++;
	i--;
	while (y < i)
	{
		swap = str[i];
		str[i] = str[y];
		str[y] = swap;
		i--;
		y++;
	}
	return (str);
}
