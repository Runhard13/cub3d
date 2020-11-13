/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:31:04 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 17:42:32 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_forward (t_all *all)
{
	if (all->map[(int)all->plr->posy][(int)(all->plr->posx + all->plr->dirx * SPEED)] != '1')
		all->plr->posx += all->plr->dirx * SPEED;

	if (all->map[(int)(all->plr->posy + all->plr->diry * SPEED)][(int)all->plr->posx] != '1')
		all->plr->posy += all->plr->diry * SPEED;
}

void move_back(t_all *all)
{
	if (all->map[(int)all->plr->posy][(int)(all->plr->posx - all->plr->dirx * SPEED)] != '1')
		all->plr->posx -= all->plr->dirx * SPEED;
	if (all->map[(int)(all->plr->posy - all->plr->diry * SPEED)][(int)all->plr->posx] != '1')
		all->plr->posy -= all->plr->diry * SPEED;
}

void rot_right (t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(-ROT) - all->plr->diry * sin(-ROT);
	all->plr->diry = olddirx * sin(-ROT) + all->plr->diry * cos(-ROT);
	oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex * cos(-ROT) - all->plr->planey * sin(-ROT);
	all->plr->planey = oldplanex * sin(-ROT) + all->plr->planey * cos(-ROT);
}

void rot_left (t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(ROT) - all->plr->diry * sin(ROT);
	all->plr->diry = olddirx * sin(ROT) + all->plr->diry * cos(ROT);
	oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex * cos(ROT) - all->plr->planey * sin(ROT);
	all->plr->planey = oldplanex * sin(ROT) + all->plr->planey * cos(ROT);
}

void strafe_left(t_all *all)
{
	if (all->map[(int)all->plr->posy][(int)(all->plr->posx - all->plr->planex * SPEED)] == '0')
		all->plr->posx -= all->plr->planex * SPEED;
	if (all->map[(int)(all->plr->posy - all->plr->planey * SPEED)][(int)all->plr->posx] == '0')
		all->plr->posy -= all->plr->planey * SPEED;
}

void strafe_right(t_all *all)
{
	if (all->map[(int)all->plr->posy][(int)(all->plr->posx + all->plr->planex * SPEED)] == '0')
		all->plr->posx += all->plr->planex * SPEED;
	if (all->map[(int)(all->plr->posy + all->plr->planey * SPEED)][(int)all->plr->posx] == '0')
		all->plr->posy += all->plr->planey * SPEED;
}
