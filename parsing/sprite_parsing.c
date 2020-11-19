/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:28:11 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/16 21:26:01 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_sprite(t_all *all)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2' && (all->map[y][0] == '1' ||
				all->map[y][0] == ' '))
			{
				all->ss[i].x = x + 0.5;
				all->ss[i].y = y + 0.5;
				all->item->sprite_count++;
				x++;
				i++;
			}
			else
				x++;
		}
		y++;
	}
}

void	parse_sprite_count(t_all *all)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2' && (all->map[y][0] == '1' ||
				all->map[y][0] == ' '))
			{
				all->item->sprite_count++;
				x++;
				i++;
			}
			else
				x++;
		}
		y++;
	}
}
