/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:30:59 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 13:27:12 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	char			lettre;
	unsigned int	i;

	str = (char*)s;
	lettre = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == lettre)
			return (str + i);
		i++;
	}
	return (0);
}
