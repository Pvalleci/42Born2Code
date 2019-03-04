/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:41:29 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:41:32 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (char*)malloc(sizeof(*mem) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		mem[i] = '\0';
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
