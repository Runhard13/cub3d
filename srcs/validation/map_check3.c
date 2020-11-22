/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:23:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/22 22:37:01 by cdrennan         ###   ########.fr       */
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

void find_map_max (t_all *all, int y)
{
	int x;
	int x_max;
	int x_min;

	x = 0;
	x_max = 0;
	x_min = 1000;
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			x++;
		}
		if (x_max < x)
			x_max = x;
		if (x_min > x)
			x_min = x;
		x = 0;
		y++;
	}
	all->x_map_max = x_max;
	all->y_map_max = y - 1;
	all->x_map_min = x_min;
}

int if_notwall_left(t_all *all, int x, int y)
{
	int y_ret;

	y_ret = y;
	while ((ft_strchr(NOTWALL, all->map[y][x])
			&& y < all->y_map_max))
		y++;
	if (all->map[y][x] == '1')
		y_ret++;
	else
		return (error(all, "Unclosed map notwall left"));
	return (y_ret);
}