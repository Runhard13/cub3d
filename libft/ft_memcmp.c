/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:49:11 by null              #+#    #+#             */
/*   Updated: 2020/05/30 18:01:51 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (n == 0 || ptr == ptr2)
		return (0);
	i = 0;
	while (n)
	{
		if (ptr[i] != ptr2[i])
			return ((int)(ptr[i] - ptr2[i]));
		i++;
		n--;
	}
	return (0);
}
