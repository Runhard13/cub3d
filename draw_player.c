/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:01:29 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/06 16:05:35 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void draw_player (t_data img, int x_start, int y_start, int size)
{
	int x = x_start;
	int y = y_start;

	while (y++ < size + y_start)
	{
		x = x_start;
		while (x++ < size + x_start)
		{
			my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		}
	}
}

void draw_player_ray (t_all *all)
{
	//{
		t_plr plr = *all->plr;
		//all->ray->y = all->plr->y;
		//all->ray->x = all->plr->x;

		//plr.fov = M_PI/6;
		//plr.left_ray = plr.pov - plr.fov / 2;
		//plr.right_ray = plr.pov + plr.fov / 2;

	//	while (plr.left_ray < plr.right_ray)
	//	{

			//plr.x = all->ray->x;
			//plr.y = all->ray->y;
		//	while (all->map [(int)plr.y / SCALE][(int)plr.x / SCALE] != '1')
		//	{
		//		plr.x += cos(plr.pov);
		//		plr.y += sin(plr.pov);
		//		my_mlx_pixel_put(all->win, plr.x, plr.y, 0xFFFFFF);
		//	}
			//plr.left_ray += plr.fov / 1920;
//		}
//	}
}