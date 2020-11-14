/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:20:21 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 17:30:44 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_path_tex(t_all *all)
{
	int		y;
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

int	check_starting_point(t_all *all)
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
			if (all->map[y][x] == 'N' && (all->map[y][x + 1] == '0' ||
										  all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				i++;
			if (all->map[y][x] == 'W' && (all->map[y][x + 1] == '0' ||
										  all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				i++;
			if (all->map[y][x] == 'S' && (all->map[y][x + 1] == '0' ||
										  all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				i++;
			if (all->map[y][x] == 'E' && (all->map[y][x + 1] == '0' ||
										  all->map[y][x + 1] == '1' || all->map[y][x + 1] == '2'))
				i++;
			x++;
		}
		y++;
	}
	return(i > 1 ? 0 : 1);
}

int	check_floor_sky(t_all *all)
{
	int		y;
	int i;

	y = 0;
	i = 0;
	while (all->map[y])
	{
		if(all->map[y][0] == 'C' || all->map[y][0] == 'F')
			i++;
	y++;
	}
	return (i == 2 ? 1 : 0);
}

int validate_map(t_all *all)
{
	if(!(check_starting_point(all)))
		return (error(all, "More than 1 starting point"));
	if(!(check_path_tex(all)))
		return (error(all, "Invalid texture config in map"));
	if(!(check_floor_sky(all)))
		return (error(all, "Invalid floor or sky color"));

	return (1);
}