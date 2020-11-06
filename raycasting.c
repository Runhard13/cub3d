/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:57:35 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/06 16:24:09 by cdrennan         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void raycaster (t_all *all)
 {
	 t_plr plr = *all->plr;
	 plr.ray_x = plr.x;
	 plr.ray_y = plr.y;

	 plr.fov = M_PI/3;
	 plr.left_ray = plr.pov - plr.fov / 2;
	 plr.right_ray = plr.pov + plr.fov / 2;

	 while (plr.left_ray <= plr.right_ray)
	 {

	 	plr.x = plr.ray_x;
	 	plr.y = plr.ray_y;
	 	while (all->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] != '1')
		{
	 		plr.x += cos(plr.left_ray);
	 		plr.y += sin(plr.left_ray);
	 		my_mlx_pixel_put(all->win, plr.x, plr.y, 0xFFFFFF);
		}
		plr.left_ray += plr.fov / 1920;
	 }
 }