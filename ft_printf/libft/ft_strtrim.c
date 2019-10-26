/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:39:42 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/04 15:18:31 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		y;
	int		z;

	if (!s)
		return (NULL);
	i = 0;
	y = ft_strlen(s);
	if (y == 0)
		return ((char*)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[y] == ' ' || s[y] == '\t' || s[y] == '\n' || s[y] == '\0')
		y--;
	if (y < i)
		y = i;
	if (!(str = (char*)malloc(sizeof(char) * (y - i + 2))))
		return (NULL);
	z = 0;
	while (i <= y)
		str[z++] = s[i++];
	str[z] = '\0';
	return (str);
}
