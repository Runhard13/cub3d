/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:37:10 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 18:43:44 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_player(t_all *all)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' && (all->map[y][x + 1] == '0' ||
			all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				player_north(all, x, y);
			if (all->map[y][x] == 'W' && (all->map[y][x + 1] == '0' ||
			all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				player_west(all, x, y);
			if (all->map[y][x] == 'S' && (all->map[y][x + 1] == '0' ||
			all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				player_south(all, x, y);
			if (all->map[y][x] == 'E' && (all->map[y][x + 1] == '0' ||
			all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				player_east(all, x, y);
			x++;
		}
		y++;
	}
}
