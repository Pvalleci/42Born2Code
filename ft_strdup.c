/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:44:44 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/15 16:45:30 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		cpy[i] = (char)s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
