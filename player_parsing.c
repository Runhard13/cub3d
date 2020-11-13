/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:37:10 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 15:38:14 by cdrennan         ###   ########.fr       */
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
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 0;
				all->plr->dirY = -1;
				all->plr->planeY = 0;
				all->plr->planeX = 0.66;
				x++;
			}
			if (all->map[y][x] == 'W' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = -1;
				all->plr->dirY = 0;
				all->plr->planeY = -0.66;
				all->plr->planeX = 0;
				x++;
			}
			if (all->map[y][x] == 'S' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 0;
				all->plr->dirY = 1;
				all->plr->planeY = 0;
				all->plr->planeX = -0.66;
				x++;
			}
			if (all->map[y][x] == 'E' && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2' ))
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 1;
				all->plr->dirY = 0;
				all->plr->planeY = 0.66;
				all->plr->planeX = 0;
				x++;
			}

			else
				x++;
		}

		y++;
	}
}
