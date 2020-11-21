/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:01:54 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/21 20:58:17 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rays_calc(t_all *all, int x)
{
	double camera_x;

	camera_x = 2 * x / (double)all->w - 1;
	all->cast->raydirx = all->plr->dirx + all->plr->planex * camera_x;
	all->cast->raydiry = all->plr->diry + all->plr->planey * camera_x;
	all->cast->map_x = (int)(all->plr->posx);
	all->cast->map_y = (int)(all->plr->posy);
	all->cast->delta_x = fabs(1 / all->cast->raydirx);
	all->cast->delta_y = fabs(1 / all->cast->raydiry);
}

void	step_calc(t_all *all)
{
	if (all->cast->raydirx < 0)
	{
		all->cast->step_x = -1;
		all->cast->side_x =
				(all->plr->posx - all->cast->map_x) * all->cast->delta_x;
	}
	else
	{
		all->cast->step_x = 1;
		all->cast->side_x =
				(all->cast->map_x + 1.0 - all->plr->posx) * all->cast->delta_x;
	}
	if (all->cast->raydiry < 0)
	{
		all->cast->step_y = -1;
		all->cast->side_y =
				(all->plr->posy - all->cast->map_y) * all->cast->delta_y;
	}
	else
	{
		all->cast->step_y = 1;
		all->cast->side_y =
				(all->cast->map_y + 1.0 - all->plr->posy) * all->cast->delta_y;
	}
}

void	preform_dda(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->cast->side_x < all->cast->side_y)
		{
			all->cast->side_x += all->cast->delta_x;
			all->cast->map_x += all->cast->step_x;
			all->cast->side = 0;
		}
		else
		{
			all->cast->side_y += all->cast->delta_y;
			all->cast->map_y += all->cast->step_y;
			all->cast->side = 1;
		}
		if (all->map[all->cast->map_y][all->cast->map_x] == '1')
			hit = 1;
	}
}
