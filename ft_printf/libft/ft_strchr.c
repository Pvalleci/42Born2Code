/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:29:02 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/14 16:07:19 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	lettre;
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	lettre = (char)c;
	if (lettre == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == lettre)
			return (str + i);
		i++;
	}
	return (NULL);
}
