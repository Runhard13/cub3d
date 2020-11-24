/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:27:51 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 20:30:17 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		img_del(t_all *all, t_tex *tex)
{
	mlx_destroy_image(all->img->mlx, tex->tex_img);
	free(tex);
}

void		destroy_images(t_all *all)
{
	if (all->north->tex_width != 0)
		img_del(all, all->north);
	if (all->south->tex_width != 0)
		img_del(all, all->south);
	if (all->west->tex_width != 0)
		img_del(all, all->west);
	if (all->east->tex_width != 0)
		img_del(all, all->east);
	if (all->sprite->tex_width != 0)
		img_del(all, all->sprite);
}

void		free_tab(char **tab, size_t size)
{
	while (size--)
		free(tab[size]);
	free(tab);
}

int			free_all(t_all *all)
{
	if (all->map)
		free_tab(all->map, all->map_size);
	if (all->map_sp_size)
		free_tab(all->map_sp, all->map_sp_size - 1);
	if (all->zbuffer)
		free(all->zbuffer);
	if (all->item->spr_ord)
		free(all->item->spr_ord);
	if (all->item->spr_dist)
		free(all->item->spr_dist);
	destroy_images(all);
	if (all->img->mlx_win)
		mlx_destroy_window(all->img->mlx, all->img->mlx_win);
	exit(0);
}
