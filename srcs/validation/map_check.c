/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:20:21 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/22 15:47:02 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_resolution(t_all *all)
{
	int	y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'R')
			i++;
		y++;
	}
	return (i == 1 ? 1 : 0);
}

int		check_path_tex(t_all *all)
{
	int	y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		if ((all->map[y][0] == 'N' && all->map[y][1] == 'O') ||
			(all->map[y][0] == 'S' && all->map[y][1] == 'O') ||
			(all->map[y][0] == 'W' && all->map[y][1] == 'E') ||
			(all->map[y][0] == 'E' && all->map[y][1] == 'A'))
			i++;
		y++;
	}
	return (i == 4 ? 1 : 0);
}

int		check_starting_point(t_all *all)
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
			if (starting_points(all, x, y))
				i++;
			x++;
		}
		y++;
	}
	return (i > 1 ? 0 : 1);
}

int		check_floor_sky(t_all *all)
{
	int	y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'C' || all->map[y][0] == 'F')
			i++;
		y++;
	}
	return (i == 2 ? 1 : 0);
}

int		validate_map(t_all *all)
{
	if (!(check_starting_point(all)))
		return (error(all, "More than 1 starting point"));
	if (!(check_path_tex(all)))
		return (error(all, "Invalid texture config in map"));
	if (!(check_floor_sky(all)))
		return (error(all, "Invalid floor or sky color"));
	if (!(check_resolution(all)))
		return (error(all, "Invalid resolution"));
	if (!(map_check(all)))
		return (error(all, "Invalid map"));
	return (1);
}
