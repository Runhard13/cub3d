/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/21 20:58:17 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rot_right(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(-ROT) - all->plr->diry * sin(-ROT);
	all->plr->diry = olddirx * sin(-ROT) + all->plr->diry * cos(-ROT);
	oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex *
			cos(-ROT) - all->plr->planey * sin(-ROT);
	all->plr->planey = oldplanex * sin(-ROT) + all->plr->planey * cos(-ROT);
}

void	rot_left(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(ROT) - all->plr->diry * sin(ROT);
	all->plr->diry = olddirx * sin(ROT) + all->plr->diry * cos(ROT);
	oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex *
			cos(ROT) - all->plr->planey * sin(ROT);
	all->plr->planey = oldplanex * sin(ROT) + all->plr->planey * cos(ROT);
}

int		key_press(int keycode, t_all *all)
{
	mlx_clear_window(all->img->mlx, all->img->mlx_win);
	if (keycode == W || keycode == UP)
		move_forward(all);
	if (keycode == S || keycode == DOWN)
		move_back(all);
	if (keycode == E || keycode == RIGHT)
		rot_left(all);
	if (keycode == Q || keycode == LEFT)
		rot_right(all);
	if (keycode == A)
		strafe_left(all);
	if (keycode == D)
		strafe_right(all);
	if (keycode == ESC)
	{
		free_all(all);
		exit(0);
	}
	sky_floor(all);
	drawscreen(all);
	return (0);
}
