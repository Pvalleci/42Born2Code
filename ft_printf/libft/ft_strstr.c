/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:01:44 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 17:03:22 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	str = (char*)haystack;
	if (needle[y] == '\0')
		return (str);
	while (str[i])
	{
		y = 0;
		while (str[i] == needle[y])
		{
			if (needle[y + 1] == '\0')
				return (str + i - y);
			i++;
			y++;
		}
		i = i - y;
		i++;
	}
	return (NULL);
}
