/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:53:39 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/19 12:53:40 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n && s[i])
	{
		cpy[i] = (char)s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
