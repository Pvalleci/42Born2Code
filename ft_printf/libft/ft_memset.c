/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:40:17 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 13:36:52 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str;
	char			lettre;

	str = (char*)b;
	lettre = (char)c;
	i = 0;
	while (i < len)
	{
		str[i] = lettre;
		i++;
	}
	return (str);
}
