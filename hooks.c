/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/08 19:12:49 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             key_press(int keycode, t_all *all)
{

	mlx_clear_window(all->img->mlx, all->img->mlx_win);

	if (keycode == W || keycode == UP)
	{
		if (all->map[(int)(all->plr->posX + all->plr->dirX * moveSpeed)][(int)(all->plr->posY)] == '0')
			all->plr->posX += all->plr->dirX * moveSpeed;
		if(all->map[(int)(all->plr->posX)][(int)(all->plr->posY + all->plr->dirY * moveSpeed)] == '0')
			all->plr->posY += all->plr->dirY * moveSpeed;
	}
	if (keycode == S || keycode == DOWN)
	{
		if(all->map[(int)(all->plr->posX - all->plr->dirX * moveSpeed)][(int)(all->plr->posY)] == '0')
			all->plr->posX -= all->plr->dirX * moveSpeed;
		if(all->map[(int)(all->plr->posX)][(int)(all->plr->posY - all->plr->dirY * moveSpeed)] == '0')
			all->plr->posY -= all->plr->dirY * moveSpeed;
	}
	if (keycode == E || keycode == RIGHT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = all->plr->dirX;
		all->plr->dirX = all->plr->dirX * cos(-rotSpeed) - all->plr->dirY * sin(-rotSpeed);
		all->plr->dirY = oldDirX * sin(-rotSpeed) + all->plr->dirY * cos(-rotSpeed);
		double oldPlaneX = all->plr->planeX;
		all->plr->planeX = all->plr->planeX * cos(-rotSpeed) - all->plr->planeY * sin(-rotSpeed);
		all->plr->planeY = oldPlaneX * sin(-rotSpeed) + all->plr->planeY * cos(-rotSpeed);
	}
	if (keycode == Q || keycode == LEFT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = all->plr->dirX;
		all->plr->dirX = all->plr->dirX * cos(rotSpeed) - all->plr->dirY * sin(rotSpeed);
		all->plr->dirY = oldDirX * sin(rotSpeed) + all->plr->dirY * cos(rotSpeed);
		double oldPlaneX = all->plr->planeX;
		all->plr->planeX = all->plr->planeX * cos(rotSpeed) - all->plr->planeY * sin(rotSpeed);
		all->plr->planeY = oldPlaneX * sin(rotSpeed) + all->plr->planeY * cos(rotSpeed);
	}
	if (keycode == ESC)
		exit(0);

	big_square(all);
	drawscreen(all);
	return (0);
}

