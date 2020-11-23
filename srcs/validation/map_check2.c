/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:37:42 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 13:16:07 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

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

int		check_horizontal(t_all *all, int y)
{
	int x;

	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
				x++;
			else if (all->map[y][x] == ' ')
				x = if_space(all, x, y);
			else if (ft_strchr(NOTWALL, all->map[y][x]))
			{
				x = if_notwall(all, x, y);
			}
		}
		y++;
	}
	return (0);
}

int		check_horizontal_back(t_all *all, int y)
{
	int x;
	int y_start;

	y_start = all->y_map_max;
	while (y_start > y)
	{
		x = 0;
		while (all->map[y_start][x])
		{
			if (all->map[y_start][x] == '1')
				x++;
			else if (all->map[y_start][x] == ' ')
				x = if_space_back(all, x, y, y_start);
			else if (ft_strchr(NOTWALL, all->map[y_start][x]))
			{
				x = if_notwall_back(all, x, y, y_start);
			}
		}
		y_start--;
	}
	return (0);
}

int check_left( t_all *all, int y)
{
	int x;
	int y_start;

	x = 0;
	y_start = y;
	while (x <= all->x_map_min)
	{
		while (y < all->y_map_max - 1)
		{
			if (all->map[y][x] == '1')
				y++;
			else if (all->map[y][x] == ' ')
				y = if_space_left(all, x, y);
			else if (ft_strchr(NOTWALL, all->map[y][x]))
				y = if_notwall_left(all, x, y);
		}
		x++;
		y = y_start;
	}
	y = y_start;
	extra_len_check(all, y);
	return (0);
}


int		map_check(t_all *all)
{
	int y;

	y = 0;
	while (find_char(CONFIG_CHR, all->map[y][0]))
		y++;
	find_map_max(all, y);
	all->map_sp = malloc(all->y_map_max * sizeof(char*));
	check_forbidden(all, y);
	make_space_map (all, y);
	mapcheck(all);
	//check_horizontal(all, y);
	//check_horizontal_back(all, y);
	//check_left(all, y);
	//check_left_back(all, y);
	//map_ccceck(all, y);
	//ft_mapcheck(all, y);
	return (1);
}
