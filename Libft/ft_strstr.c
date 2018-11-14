/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:40:46 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 15:40:49 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*to_f;
	char	*tas;

	i = 0;
	j = 0;
	to_f = (char *)to_find;
	tas = (char *)str;
	if (to_f[i] == '\0')
		return (tas);
	while (tas[i])
	{
		while (to_f[j] == tas[i + j])
		{
			if (to_f[j + 1] == '\0')
				return (tas + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
