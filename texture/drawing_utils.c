/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:59:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/16 21:26:01 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	sky_floor(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y++ < (all->h / 2 - 1))
	{
		x = 0;
		while (x++ < (all->w - 1))
		{
			my_mlx_pixel_put(all->img, x, y, all->sky_color);
		}
	}
	while (y++ >= (all->h / 2 - 1) && y < all->h - 1)
	{
		x = 0;
		while (x++ < (all->w - 1))
		{
			my_mlx_pixel_put(all->img, x, y, all->floor_color);
		}
	}
}

void	drawscreen(t_all *all)
{
	int		x;
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x++ < all->w)
	{
		rays_calc(all, x);
		step_calc(all);
		preform_dda (all);
		if (all->cast->side == 0)
			all->cast->perp_wall_dist = (all->cast->map_x - all->plr->posx + (1 - all->cast->step_x) / 2.0) / all->cast->raydirx;
		else
			all->cast->perp_wall_dist = (all->cast->map_y - all->plr->posy + (1 - all->cast->step_y) / 2.0) / all->cast->raydiry;
		all->cast->line_h = (int)(all->h / all->cast->perp_wall_dist);
		draw_start = -all->cast->line_h / 2 + all->h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = all->cast->line_h / 2 + all->h / 2;
		if (draw_end >= all->h)
			draw_end = all->h - 2;
		tex_draw(all, x, draw_start, draw_end);
		all->zbuffer[x] = all->cast->perp_wall_dist;
	}
	draw_sprite(all);
	mlx_put_image_to_window(all->img, all->img->mlx_win, all->img->img, 0, 0);
	if(all->screenshot == 1)
	{
		save_screenshot(all);
		all->screenshot = 0;
	}
}
