/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/10 17:07:48 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             key_press(int keycode, t_all *all)
{

	mlx_clear_window(all->img->mlx, all->img->mlx_win);

	if (keycode == W || keycode == UP)
	{
		if (all->map[(int)(all->plr->posY + all->plr->dirY * moveSpeed)][(int)(all->plr->posX)] != '1')
			all->plr->posX += all->plr->dirX * moveSpeed;
		if(all->map[(int)(all->plr->posY)][(int)(all->plr->posX + all->plr->dirX * moveSpeed)] != '1')
			all->plr->posY += all->plr->dirY * moveSpeed;
	}
	if (keycode == S || keycode == DOWN)
	{
		if(all->map[(int)(all->plr->posY - all->plr->dirY * moveSpeed)][(int)(all->plr->posX)] != '1')
			all->plr->posX -= all->plr->dirX * moveSpeed;
		if(all->map[(int)(all->plr->posY)][(int)(all->plr->posX - all->plr->dirX * moveSpeed)] != '1')
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
	if (keycode == A )
	{
		if (all->map[(int)all->plr->posY] [(int)(all->plr->posX - all->plr->planeX * moveSpeed)] != '1')
			all->plr->posX -= all->plr->planeX * moveSpeed;
		if (all->map[(int)(all->plr->posY - all->plr->planeY * moveSpeed)][(int)all->plr->posX] != '1')
			all->plr->posY -= all->plr->planeY * moveSpeed;
	}
	if (keycode == D )
	{
		if (all->map[(int)all->plr->posY][(int)(all->plr->posX + all->plr->planeX * moveSpeed)] != '1')
			all->plr->posX += all->plr->planeX * moveSpeed;
		if (all->map[(int)(all->plr->posY + all->plr->planeY * moveSpeed)][(int)all->plr->posX] != '1')
			all->plr->posY += all->plr->planeY * moveSpeed;
	}

	if (keycode == ESC)
		exit(0);

	sky_floor(all);
	drawscreen(all);
	return (0);
}

