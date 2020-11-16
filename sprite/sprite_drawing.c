/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:30:25 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/16 21:25:57 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_color(t_all *all)
{
	int color;
	int y;
	int d;

	if (all->item->transform_y > 0 && all->item->draw_start_x > 0 &&
		all->item->draw_start_x < all->w &&
		all->item->transform_y < all->zbuffer[all->item->draw_start_x])
	{
		y = all->item->draw_start_y;
		while (y < all->item->draw_end_y)
		{
			d = (y) * 256 - all->h * 128 + all->item->sprite_h * 128;
			all->item->tex_y = ((d * all->
					sprite->tex_height) / all->item->sprite_h) / 256;
			color = get_color(all->sprite,
					all->item->tex_x, all->item->tex_y);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->img,
						all->item->draw_start_x, y, color);
			y++;
		}
	}
}

void	drawing(t_all *all)
{
	while (all->item->draw_start_x < all->item->draw_end_x)
	{
		all->item->tex_x = (256 * (all->item->draw_start_x -
				(-all->item->sprite_w / 2 + all->item->sprite_screen_x)) *
				all->sprite->tex_width / all->item->sprite_w) / 256;
		find_color(all);
		all->item->draw_start_x++;
	}
}

void	find_start_end(t_all *all)
{
	all->item->draw_start_y = -all->item->sprite_h / 2 + all->h / 2;
	if (all->item->draw_start_y < 0)
		all->item->draw_start_y = 0;
	all->item->draw_end_y = all->item->sprite_h / 2 + all->h / 2;
	if (all->item->draw_end_y >= all->h)
		all->item->draw_end_y = all->h - 1;
	all->item->sprite_w = abs((int)(all->h / (all->item->transform_y)));
	all->item->draw_start_x =
			-all->item->sprite_w / 2 + all->item->sprite_screen_x;
	if (all->item->draw_start_x < 0)
		all->item->draw_start_x = 0;
	all->item->draw_end_x =
			all->item->sprite_w / 2 + all->item->sprite_screen_x;
	if (all->item->draw_end_x >= all->w)
		all->item->draw_end_x = all->w - 1;
}

void	find_sprite_h(t_all *all)
{
	all->item->inv_det = 1.0 / (all->plr->planex
			* all->plr->diry - all->plr->dirx * all->plr->planey);
	all->item->transform_x = all->item->inv_det
			* (all->plr->diry * all->item->sprite_x -
			all->plr->dirx * all->item->sprite_y);
	all->item->transform_y = all->item->inv_det
			* (-all->plr->planey * all->item->sprite_x +
			all->plr->planex * all->item->sprite_y);
	all->item->sprite_screen_x = (int)((all->w / 2) *
			(1 + all->item->transform_x / all->item->transform_y));
	all->item->sprite_h = abs((int)(all->h / (all->item->transform_y)));
}

void	draw_sprite(t_all *all, int *spr_ord, double *spr_dist)
{
	int i;

	i = 0;
	while (i < all->item->sprite_count)
	{
		spr_ord[i] = i;
		spr_dist[i] = ((all->plr->posx - all->ss[i].x) *
				(all->plr->posx - all->ss[i].x) +
				(all->plr->posy - all->ss[i].x) *
				(all->plr->posy - all->ss[i].x));
		i++;
	}
	spr_sort(spr_ord, spr_dist, all->item->sprite_count);
	i = 0;
	while (i < all->item->sprite_count)
	{
		all->item->sprite_x = all->ss[spr_ord[i]].x - all->plr->posx;
		all->item->sprite_y = all->ss[spr_ord[i]].y - all->plr->posy;
		find_sprite_h(all);
		find_start_end(all);
		drawing(all);
		i++;
	}
}
