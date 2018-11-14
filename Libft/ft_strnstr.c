/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:16:14 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 16:16:16 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = (int)len;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (i < n && str[i] && to_find[j])
	{
		j = 0;
		while (to_find[j] == str[i] && i < n)
		{
			if (to_find[j + 1] == '\0' && j < n)
				return ((char *)str + (i - j));
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
