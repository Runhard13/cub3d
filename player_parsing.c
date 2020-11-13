/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:37:10 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 17:31:20 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_player (t_all *all)
{
	int x = 0;
	int y = 0;

	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posx = x + 0.5;
				all->plr->posy = y + 0.5;
				all->plr->dirx = 0;
				all->plr->diry = -1;
				all->plr->planey = 0;
				all->plr->planex = 0.66;
				x++;
			}
			if (all->map[y][x] == 'W' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posx = x + 0.5;
				all->plr->posy = y + 0.5;
				all->plr->dirx = -1;
				all->plr->diry = 0;
				all->plr->planey = -0.66;
				all->plr->planex = 0;
				x++;
			}
			if (all->map[y][x] == 'S' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posx = x + 0.5;
				all->plr->posy = y + 0.5;
				all->plr->dirx = 0;
				all->plr->diry = 1;
				all->plr->planey = 0;
				all->plr->planex = -0.66;
				x++;
			}
			if (all->map[y][x] == 'E' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posx = x + 0.5;
				all->plr->posy = y + 0.5;
				all->plr->dirx = 1;
				all->plr->diry = 0;
				all->plr->planey = 0.66;
				all->plr->planex = 0;
				x++;
			}

			else
				x++;
		}

		y++;
	}
}
