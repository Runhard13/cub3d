/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:37:10 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/18 21:01:04 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_player(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (find_char("NSEW", all->map[y][x]) && (all->map[y][x + 1] == '0' || all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				player_init(all, x, y, all->map[y][x]);
			x++;
		}
		y++;
	}
}

void player_init (t_all *all, int x, int y, char c)
{
	if (c == 'N' || c == 'S')
	{
		all->plr->dirx = 0;
		all->plr->diry = (c == 'N') ? -1 : 1;
		all->plr->planey = 0;
		all->plr->planex = (c == 'N') ? 0.66 : -0.66;
	}

	if (c == 'E' || c == 'W')
	{
		all->plr->dirx = (c == 'E') ? 1 : -1;
		all->plr->planey = (c == 'E') ? 0.66 : -0.66;
		all->plr->planex = 0;
	}
	all->plr->posx = x;
	all->plr->posy = y;
}
