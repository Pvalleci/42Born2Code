/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:34:35 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:34:38 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;
	int		j;

	j = (int)n;
	i = 0;
	str = (char*)s;
	while (i < j)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
