/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:42:28 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/10 16:49:21 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int wall_side (int side, double rayDirX, double rayDirY)
{
	if (side)
		return ((rayDirY < 0) ? (texN) : (texS));
	return ((rayDirX < 0) ? (texW) : (texE));
}

void tex_open (t_all *all)
{

	all->north->path = "./pics/AnyConv.com__redbrick.xpm";
	all->south->path = "./pics/AnyConv.com__bluestone.xpm";
	all->east->path = "./pics/AnyConv.com__greystone.xpm";
	all->west->path = "./pics/AnyConv.com__wood.xpm";

	all->north->tex_img = mlx_xpm_file_to_image(all->img->mlx, all->north->path, &all->north->tex_width, &all->north->tex_height);
	all->south->tex_img = mlx_xpm_file_to_image(all->img->mlx, all->south->path, &all->south->tex_width, &all->south->tex_height);
	all->east->tex_img = mlx_xpm_file_to_image(all->img->mlx, all->east->path, &all->east->tex_width, &all->east->tex_height);
	all->west->tex_img = mlx_xpm_file_to_image(all->img->mlx, all->west->path, &all->west->tex_width, &all->west->tex_height);
}


void get_tex_data (t_all *all)
{

	all->north->addr = mlx_get_data_addr(all->north->tex_img, &all->north->bits_per_pixel, &all->north->line_length, &all->north->endian);
	all->south->addr = mlx_get_data_addr(all->south->tex_img, &all->south->bits_per_pixel, &all->south->line_length, &all->south->endian);
	all->east->addr = mlx_get_data_addr(all->east->tex_img, &all->east->bits_per_pixel, &all->east->line_length, &all->east->endian);
	all->west->addr = mlx_get_data_addr(all->west->tex_img, &all->west->bits_per_pixel, &all->west->line_length, &all->west->endian);
	all->sprite->addr = mlx_get_data_addr(all->sprite->tex_img, &all->sprite->bits_per_pixel, &all->sprite->line_length, &all->sprite->endian);
}

int get_color (t_tex *tex, int x, int y)
{
	char *dst;
	int color;

	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	color = *(unsigned int*)dst;

	return (color);

}