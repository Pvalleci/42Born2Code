/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:43:18 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/14 14:25:43 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	lettre;
	char	*str;

	lettre = (char)c;
	str = (char*)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == lettre)
			return (str + i);
		i--;
	}
	return (NULL);
}
