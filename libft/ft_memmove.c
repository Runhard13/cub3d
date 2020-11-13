/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:51:57 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 12:13:23 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

void		*ft_memmove(void *dest, const void *source, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)source;
	d = (char *)dest;
	if (s < d)
	{
		while (len)
		{
			len--;
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}
