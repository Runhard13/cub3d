/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 20:23:34 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int             key_press(int keycode, t_all *all)
{

	mlx_clear_window(all->win->mlx, all->win->mlx_win);
	if (keycode == W || keycode == UP)
	{
		all->plr->y += sin(all->plr->pov) * 4;
		all->plr->x += cos(all->plr->pov) * 4;
	}

	if (keycode == S || keycode == DOWN)
	{
		all->plr->y -= sin(all->plr->pov) * 4;
		all->plr->x -= cos(all->plr->pov) * 4;
	}

	if (keycode == A || keycode == LEFT)
		all->plr->pov -= 6;
	if (keycode == D || keycode == RIGHT)
		all->plr->pov += 6;
	if (keycode == ESC)
		exit(0);
	redraw_map(all);

	return (0);
}

