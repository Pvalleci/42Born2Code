/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:42:10 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:42:12 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	s = (char *)malloc(sizeof(s) * j + 1);
	j--;
	while (j > 0)
	{
		s[i] = str[j];
		i++;
		j--;
	}
	s[i] = str[j];
	i++;
	s[i] = '\0';
	return (s);
}
