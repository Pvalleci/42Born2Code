/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:29:59 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/13 14:32:15 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	y;

	str = (char*)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (str);
	while (i < len && str[i])
	{
		y = 0;
		while (str[i] == needle[y] && i < len)
		{
			if (needle[y + 1] == '\0' && y < len)
				return (str + i - y);
			i++;
			y++;
		}
		i = i - y;
		i++;
	}
	return (NULL);
}
