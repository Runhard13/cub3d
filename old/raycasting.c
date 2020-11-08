/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:57:35 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 23:31:28 by cdrennan         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

 void raycaster (t_all *all)
 {
	double dist;
	int x = 0;
	double height= 0;
	 all->plr->ray_x = all->plr->x;
	 all->plr->ray_y = all->plr->y;

	 all->plr->fov = 0.66/1;
	 all->plr->left_ray = all->plr->pov - all->plr->fov / 2;
	 all->plr->right_ray = all->plr->pov + all->plr->fov / 2;

	 while (all->plr->left_ray < all->plr->right_ray)
	 {

	 	all->plr->ray_x = all->plr->x;
	 	all->plr->ray_y = all->plr->y;
	 	while (all->map[(int)(all->plr->ray_y)][(int)(all->plr->ray_x)] != '1')
		{
	 		all->plr->ray_x += cos(all->plr->left_ray);
	 		all->plr->ray_y += sin(all->plr->left_ray);
		}
		dist = (fabs((all->plr->x - all->plr->ray_x) * cos(all->plr->left_ray)) + fabs((all->plr->y - all->plr->ray_y) * cos(all->plr->left_ray)));
	 	height = h / dist * cos(all->plr->left_ray);
	 	draw_line(all, height, x);
	 	x++;
		all->plr->left_ray += all->plr->fov / w;
	 }
	 mlx_put_image_to_window(all->img, all->img->mlx_win, all->img->img, 0, 0);
 }