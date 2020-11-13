/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:53:58 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 12:13:23 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t pos;
	size_t i;

	pos = 0;
	if (!*little)
		return ((char*)big);
	while (big[pos] != '\0' && pos < len)
	{
		if (big[pos] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[pos + i] == little[i] && \
			(pos + i) < len)
				i++;
			if (little[i] == '\0')
				return ((char *)&big[pos]);
		}
		pos++;
	}
	return (NULL);
}
