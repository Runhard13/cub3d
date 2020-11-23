/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:39:38 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 00:25:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int find_len (t_all *all, int y)
{
	int x;

	x = 0;
	while (all->map[y][x])
		x++;
	return (x);
}

int first_line(t_all *all, int y)
{
	int x;

	while (find_len(all, y) <= all->x_map_min)
		y++;
	x = find_len(all, y) - 1;
	while (x > all->x_map_min - 1)
	{
		if (all->map[y][x] == '1' || all->map[y][x] == ' ')
			x--;
		else if (ft_strchr(NOTWALL, all->map[y][x]))
			return (error(all, "Unclosed map 1st line"));
	}
	y++;
	return (middle_line(all, y));
}

int middle_line (t_all *all ,int y)
{
	int x;
	int i;
	int y_start;
	int k;

	i = 0;
	y_start = y;
	while (find_len(all, y) > all->x_map_min)
	{
		i++;
		y++;
	}
	y = y_start;
	while (find_len(all, y) > all->x_map_min)
	{
		x = find_len(all, y) - 1;
		while (x > all->x_map_min - 1)
		{
			if (all->map[y][x] == '1' || all->map[y][x] == ' ')
				x--;
			else if (ft_strchr(NOTWALL, all->map[y][x]))
			{
				k = 0;
				while (all->map[y - k][x] != '1' && k < i)
					k++;
				if (all->map[y - k][x] != '1')
					return (error(all, "Unclosed map middle line"));
				else
					x--;
			}
		}
		y++;
	}
	return (extra_len_check(all, y));
}

int extra_len_check(t_all *all, int y)
{
	while (y < all->y_map_max - 1)
		return(first_line(all, y));
	return (0);
}

int check_left_back(t_all *all, int y)
{
	int x;
	int y_start;

	x = 0;
	y_start = all->y_map_max;
	while (x <= all->x_map_min)
	{
		while (y_start > y)
		{
			if (all->map[y_start][x] == '1')
				y_start--;
			else if (all->map[y_start][x] == ' ')
				y_start = if_space_left_back(all, x, y_start, y);
			else if (ft_strchr(NOTWALL, all->map[y_start][x]))
				y_start = if_notwall_left_back(all, x, y_start, y);
		}
		x++;
		y_start = all->y_map_max;
	}
	y_start = all->y_map_max;
	extra_len_check_back(all, y_start, y);
	return (0);
}