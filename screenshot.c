/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:08:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/19 18:06:21 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

typedef struct s_bmp_file_header
{

} t_bmp_file_header;

typedef struct s_bmp_info_header
{
	DWORD Size; // Число байтов необходимое для структуры = 40
	DWORD Width; // Ширина точечного рисунка в пикселях
	DWORD Height; // Высота точечного рисунка в пикселях
	WORD Planes; // Число плоскостей целевого устройства = 1
	WORD BitCount; // Глубина цвета, число бит на точку = 0,1,4,8,16,24,32
	DWORD Compression; // Тип сжатия = 0 для несжатого изображения
	DWORD SizeImage; // Размер изображения в байтах BitCount*Height*Width
	DWORD XPelsPerMeter; // Разрешающая способность по горизонтали
	DWORD YPelsPerMeter; // Разрешающая способность по вертикали
	DWORD ColorUsed; // Число индексов используемых цветов. Если все цвета = 0
	DWORD ColorImportant; // Число необходимых цветов = 0
} t_bmp_info_header;

*/

t_bmp_file_header get_bmp_fh (t_all *all)
{
	t_bmp_file_header f_header;

	ft_memset(&f_header, 0, sizeof(f_header));
	f_header.type = 0x4D42;
	f_header.size = 14;
	f_header.offset = 54;

	return(f_header);

}

t_bmp_info_header get_bmp_ih (t_all *all)
{
	t_bmp_info_header i_header;

	ft_memset(&i_header, 0, sizeof(i_header));

	i_header.size = 40;
	i_header.width = all->w;
	i_header.height = all->h;
	i_header.planes = 1;
	i_header.bpp = all->img->bpp;
	i_header.size_image = all->h * all->w * all->img->bpp;

	return(i_header);

}



int				save_screenshot(t_all *all)
{
	int				fd;
	t_bmp_info_header		bmp_info;
	t_bmp_file_header	bmp_file;
	int				i;

	all->img->addr = mlx_get_data_addr(all->img->img, &(all->img->bpp), &(all->img->line_length), &(all->img->endian));
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);

	bmp_file = get_bmp_fh(all);
	bmp_info = get_bmp_ih(all);

	write(fd, &bmp_file, sizeof(bmp_file));
	write(fd, &bmp_info, sizeof(bmp_info));

	i = 0;
	while (i < all->h)
	{
		write(fd, all->img->addr + (i * all->img->line_length), all->img->line_length);
		i++;
	}
	close(fd);
	return (0);
}