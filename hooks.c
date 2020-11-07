/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 20:30:26 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int             key_press(int keycode, t_all *all)
{

	mlx_clear_window(all->win->mlx, all->win->mlx_win);

	if (keycode == W || keycode == UP)
	{
		if((all->map[(int)((all->plr->y) + (sin(all->plr->pov) * SPEED)) / SCALE][(int)((all->plr->x) + (cos(all->plr->pov) * SPEED)) / SCALE] != '1'))
		{
			all->plr->y += sin(all->plr->pov) * SPEED;
			all->plr->x += cos(all->plr->pov) * SPEED;
		}
	}
	if (keycode == S || keycode == DOWN)
	{
		if((all->map[(int)((all->plr->y) - (sin(all->plr->pov) * SPEED)) / SCALE][(int)((all->plr->x) - (cos(all->plr->pov) * SPEED)) / SCALE] != '1'))
		{
			all->plr->y -= sin(all->plr->pov) * SPEED;
			all->plr->x -= cos(all->plr->pov) * SPEED;
		}
	}
	if (keycode == E || keycode == RIGHT)
	{
			all->plr->pov += M_PI/30;
	}
	if (keycode == Q || keycode == LEFT)
	{
			all->plr->pov -= M_PI/30;
	}
	if (keycode == ESC)
		exit(0);

	if (keycode == A)
	{
		if((all->map[(int)((all->plr->y) - (cos(all->plr->pov) * SPEED)) / SCALE][(int)((all->plr->x) + (sin(all->plr->pov) * SPEED)) / SCALE] != '1'))
		{
			all->plr->y -= cos(all->plr->pov) * SPEED;
			all->plr->x += sin(all->plr->pov) * SPEED;
		}
	}
	if (keycode == D)
	{
		if((all->map[(int)((all->plr->y) + (cos(all->plr->pov) * SPEED)) / SCALE][(int)((all->plr->x) - (sin(all->plr->pov) * SPEED)) / SCALE] != '1'))
		{
			all->plr->y += cos(all->plr->pov) * SPEED;
			all->plr->x -= sin(all->plr->pov) * SPEED;
		}
	}

	redraw_map(all);

	return (0);
}

