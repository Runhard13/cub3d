/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:32:46 by null              #+#    #+#             */
/*   Updated: 2020/05/30 18:06:19 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char*)destination;
	ptr2 = (unsigned char*)source;
	if (!ptr && !ptr2)
		return (NULL);
	i = 0;
	if (ptr2 > ptr)
	{
		while (i < num)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	}
	else
	{
		while (num--)
			ptr[num] = ptr2[num];
	}
	return (destination);
}
