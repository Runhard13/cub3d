/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:32:27 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 18:44:27 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_north(t_all *all, int x, int y)
{
	all->plr->posx = x + 0.5;
	all->plr->posy = y + 0.5;
	all->plr->dirx = 0;
	all->plr->diry = -1;
	all->plr->planey = 0;
	all->plr->planex = 0.66;
}

void	player_south(t_all *all, int x, int y)
{
	all->plr->posx = x + 0.5;
	all->plr->posy = y + 0.5;
	all->plr->dirx = 0;
	all->plr->diry = 1;
	all->plr->planey = 0;
	all->plr->planex = -0.66;
}

void	player_west(t_all *all, int x, int y)
{
	all->plr->posx = x + 0.5;
	all->plr->posy = y + 0.5;
	all->plr->dirx = -1;
	all->plr->diry = 0;
	all->plr->planey = -0.66;
	all->plr->planex = 0;
}

void	player_east(t_all *all, int x, int y)
{
	all->plr->posx = x + 0.5;
	all->plr->posy = y + 0.5;
	all->plr->dirx = 1;
	all->plr->diry = 0;
	all->plr->planey = 0.66;
	all->plr->planex = 0;
}
