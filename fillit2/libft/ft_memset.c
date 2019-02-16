/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:08:44 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/11 06:08:45 by juaalvar         ###   ########.fr       */
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
