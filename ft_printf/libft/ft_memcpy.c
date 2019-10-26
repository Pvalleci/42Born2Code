/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:22:13 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 13:31:35 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*strs;
	char			*strd;

	strs = (char*)src;
	strd = (char*)dst;
	i = 0;
	while (i < n)
	{
		strd[i] = strs[i];
		i++;
	}
	return (strd);
}
