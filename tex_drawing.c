/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:17:29 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 23:28:32 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_choose(t_all *all, int draw_start, int draw_end, int x)
{
	while (draw_start++ < draw_end)
	{
		all->tex->tex_y = (int)all->tex->tex_pos & (all->north->tex_height - 1);
		all->tex->tex_pos += all->tex->step;
		if (wall_side(all) == TEX_S)
			all->tex->color =
					get_color(all->south, all->tex->tex_x, all->tex->tex_y);
		if (wall_side(all) == TEX_N)
			all->tex->color =
					get_color(all->north, all->tex->tex_x, all->tex->tex_y);
		if (wall_side(all) == TEX_E)
			all->tex->color =
					get_color(all->east, all->tex->tex_x, all->tex->tex_y);
		if (wall_side(all) == TEX_W)
			all->tex->color =
					get_color(all->west, all->tex->tex_x, all->tex->tex_y);
		my_mlx_pixel_put(all->img, x, draw_start, all->tex->color);
	}
}

void	tex_draw(t_all *all, int x, int draw_start, int draw_end)
{
	if (all->cast->side == 0)
		all->tex->wall_x =
				all->plr->posy + all->cast->perp_wall_dist * all->cast->raydiry;
	else
		all->tex->wall_x =
				all->plr->posx + all->cast->perp_wall_dist * all->cast->raydirx;
	all->tex->wall_x -= floor((all->tex->wall_x));
	all->tex->tex_x =
			(int)(all->tex->wall_x * (double)(all->north->tex_width));
	if (all->cast->side == 0 && all->cast->raydirx > 0)
		all->tex->tex_x = all->north->tex_width - all->tex->tex_x - 1;
	if (all->cast->side == 1 && all->cast->raydiry < 0)
		all->tex->tex_x = all->north->tex_width - all->tex->tex_x - 1;
	all->tex->step = 1.0 * all->north->tex_height / all->cast->line_h;
	all->tex->tex_pos =
			(draw_start - all->h / 2 + all->cast->line_h / 2) * all->tex->step;
	color_choose(all, draw_start, draw_end, x);
}
