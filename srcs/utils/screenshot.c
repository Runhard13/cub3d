/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:08:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/24 10:06:49 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bitmap		get_header(t_all *all)
{
	t_bitmap header;

	ft_memset(&header, 0, sizeof(header));
	header.pixel_data_offset = 54;
	header.header_size = 40;
	header.height = all->h;
	header.width = all->w;
	header.plane = 1;
	header.bpp = (u_int16_t)(all->img->bpp);
	header.file_size = (unsigned int)(header.bpp * header.width * header.width);
	return (header);
}

int				save_screenshot(t_all *all)
{
	int				fd;
	int				i;
	t_bitmap		bmp;
	unsigned int	*line;

	all->img->addr = mlx_get_data_addr(all->img->img, &(all->img->bpp),
			&(all->img->line_length), &(all->img->endian));
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	bmp = get_header(all);
	write(fd, "BM", 2);
	write(fd, &bmp, sizeof(bmp));
	i = 0;
	while (i < all->h)
	{
		line = (unsigned int *)
				&all->img->addr[(all->h - i - 1) * all->img->line_length];
		write(fd, line, (size_t)all->img->line_length);
		i++;
	}
	close(fd);
	exit (0);
}
