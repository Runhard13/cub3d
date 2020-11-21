/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:23:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/21 20:58:17 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_forbidden(t_all *all, int y)
{
	int x;

	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (!(find_char(" 012NSEW", all->map[y][x])))
				return (error(all, "Forbidden symbols in map"));
			x++;
		}
		y++;
	}
	return (1);
}

int		starting_points(t_all *all, int x, int y)
{
	if (all->map[y][x] == 'N' && (all->map[y][x + 1] == '0' ||
	all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
		return (1);
	if (all->map[y][x] == 'W' && (all->map[y][x + 1] == '0' ||
	all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
		return (1);
	if (all->map[y][x] == 'S' && (all->map[y][x + 1] == '0' ||
	all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
		return (1);
	if (all->map[y][x] == 'E' && (all->map[y][x + 1] == '0' ||
	all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
		return (1);
	return (0);
}
