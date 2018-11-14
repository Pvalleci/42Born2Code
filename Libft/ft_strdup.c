/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:44:44 by pvalleci          #+#    #+#             */
/*   Updated: 2018/11/08 13:44:46 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(s) * (ft_strlen(s) + 1))))
		return (NULL);
	cpy = strcpy(cpy, s);
	return (cpy);
}
