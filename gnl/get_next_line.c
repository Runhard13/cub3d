/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:27:17 by cdrennan          #+#    #+#             */
/*   Updated: 2020/08/26 23:53:18 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*i;

	i = (unsigned char*)ptr;
	while (num-- > 0)
		*(i++) = (unsigned char)value;
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char *)malloc(size * num)))
		return (NULL);
	ft_bzero(ptr, num * size);
	return ((void*)ptr);
}

int		ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*temp;
	ssize_t		b_read;
	char		buf[BUFFER_SIZE + (b_read = 1)];
	static char	*crop = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	crop == NULL ? crop = ft_calloc(1, 1) : NULL;
	while (!ft_strchr(crop, '\n') && (b_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b_read] = '\0';
		temp = crop;
		crop = ft_strjoin(crop, buf);
		ft_free((void**)&temp);
	}
	if (b_read == 0)
		*line = ft_strdup(crop);
	else if (b_read > 0)
		*line = ft_substr(crop, 0, (ft_strchr(crop, '\n') - crop));
	else
		return (-1);
	temp = crop;
	crop = ft_strdup(crop + (b_read > 0 ? 1 : 0) + (ft_strlen(*line)));
	ft_free((void**)&temp);
	return (b_read == 0 ? 0 * ft_free((void **)&crop) : 1);
}
