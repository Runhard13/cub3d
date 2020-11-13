/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:28:11 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 15:39:40 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_sprite (t_all *all)
{
	int x = 0;
	int y = 0;

	while (all->map[y])
	{
		if(all->map[y][x] == '2' && (all->map[y][0] == '1' || all->map[y][0] == ' '))
		{
			all->item->x = x;
			all->item->y = y;
			all->item->sprite_count++;
			x++;
		}
		else
			x++;
		y++;
	}
}
