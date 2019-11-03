/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:11:53 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/04 14:37:18 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 'z' && str[i] >= 'a') && (!((str[i - 1] >= '0'
			&& str[i - 1] <= '9') || (str[i - 1] <= 'z' && str[i - 1] >= 'a')
			|| (str[i - 1] <= 'Z' && str[i - 1] >= 'A'))))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
