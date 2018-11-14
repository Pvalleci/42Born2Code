/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:16:56 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 10:16:59 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	char	*ch;
	char	l;
	int		i;

	l = (char)c;
	ch = (char *)str;
	i = 0;
	while (len > 0)
	{
		ch[i] = l;
		i++;
		len--;
	}
	return (ch);
}
