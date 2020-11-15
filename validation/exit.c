/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:27:51 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 22:21:26 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		destroy_images(t_all *all)
{
	if (all->north->tex_width != 0)
		mlx_destroy_image(all->img->mlx, all->north->tex_img);
	if (all->south->tex_width != 0)
		mlx_destroy_image(all->img->mlx, all->south->tex_img);
	if (all->west->tex_width != 0)
		mlx_destroy_image(all->img->mlx, all->west->tex_img);
	if (all->east->tex_width != 0)
		mlx_destroy_image(all->img->mlx, all->east->tex_img);
	if (all->sprite->tex_width != 0)
		mlx_destroy_image(all->img->mlx, all->sprite->tex_img);
}


int free_all(t_all *all)
{
	destroy_images(all);
	if (all->map)
		free(all->map);
	if (all->zbuffer)
		free(all->zbuffer);
	if (all->item->spr_ord)
		free(all->item->spr_ord);
	if (all->item->spr_dist)
		free(all->item->spr_dist);
	if(all->img->mlx_win)
		mlx_destroy_window(all->img->mlx, all->img->mlx_win);
	exit(0);
}