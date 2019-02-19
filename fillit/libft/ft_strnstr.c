/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 05:33:47 by juaalvar          #+#    #+#             */
/*   Updated: 2018/11/11 05:33:49 by juaalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	i = 0;
	found = 0;
	if (!ft_strlen(little))
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[0])
		{
			k = i;
			found = 1;
			while (big[k] && little[j] && j < len && k < len)
				if (big[k++] != little[j++])
					found = 0;
			if (found && !little[j])
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
