/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:28:11 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 17:31:20 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_sprite(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2' && (all->map[y][0] == '1' ||
										  all->map[y][0] == ' '))
			{
				all->item->x = x;
				all->item->y = y;
				all->item->sprite_count++;
				x++;
			}
			else
				x++;
		}
		y++;
	}
}
