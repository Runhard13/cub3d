/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:37:42 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 20:06:37 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		find_char(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

int		map_check(t_all *all)
{
	int y;

	y = 0;
	while (find_char(CONFIG_CHR, all->map[y][0]))
		y++;
	find_map_max(all, y);
	all->map_sp_size = all->y_map_max + 2 - y;
	if (!(all->map_sp = ft_calloc(all->map_sp_size, sizeof(char*))))
		return (error(all, "Malloc error map_sp"));
	check_forbidden(all, y);
	make_space_map(all, y);
	mapcheck(all);
	return (1);
}

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

void	find_map_max(t_all *all, int y)
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
	all->x_map_max = x_max - 1;
	all->y_map_max = y - 1;
}
