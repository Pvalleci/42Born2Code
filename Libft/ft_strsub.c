/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:30:52 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/09 12:30:53 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(str) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = (char)s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
