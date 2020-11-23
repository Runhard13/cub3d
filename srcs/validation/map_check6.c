/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:11:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 11:13:09 by cdrennan         ###   ########.fr       */
/*                                                                            */
#include "../cub3d.h"

/* ************************************************************************** */

int middle_line_back(t_all *all, int y_start, int y)
{
	int x;
	int i;
	int y_max;
	int k;

	i = 0;
	y_max = y_start;
	while (find_len(all, y_start) > all->x_map_min)
	{
		i++;
		y_start--;
	}
	y_start = y_max;
	while (find_len(all, y_start) > all->x_map_min)
	{
		x = find_len(all, y_start) - 1;
		while (x > all->x_map_min - 1)
		{
			if (all->map[y_start][x] == '1' || all->map[y_start][x] == ' ')
				x--;
			else if (ft_strchr(NOTWALL, all->map[y_start][x]))
			{
				k = 0;
				while (all->map[y_start + k][x] != '1' && k < i)
					k++;
				if (all->map[y_start + k][x] != '1')
					return (error(all, "Unclosed map middle line back"));
				else
					x--;
			}
		}
		y_start--;
	}
	return (extra_len_check_back(all, y_start, y));
}

int first_line_back(t_all *all, int y_start, int y)
{
	int x;

	while (find_len(all, y_start) <= all->x_map_min)
		y_start--;
	x = find_len(all, y_start) - 1;
	while (x > all->x_map_min - 1)
	{
		if (all->map[y_start][x] == '1' || all->map[y_start][x] == ' ')
			x--;
		else if (ft_strchr(NOTWALL, all->map[y_start][x]))
			return (error(all, "Unclosed map 1st line back"));
	}
	y++;
	return (middle_line_back(all, y_start, y));
}

int extra_len_check_back(t_all *all, int y_start,  int y)
{

	while (y_start > y)
		return (first_line_back(all, y_start, y));
	return (0);
}

int if_space_left_back(t_all *all, int x, int y_start, int y)
{
	int y_ret;

	y_ret = y_start;
	while (all->map[y_start][x] == ' ' && y_start > y)
		y_start--;
	if (all->map[y_start][x] == '1')
		y_ret--;
	else if (y_start == y)
		y_ret--;
	else
		return (error(all, "Unclosed map left back"));
	return (y_ret);
}

int if_notwall_left_back(t_all *all, int x, int y_start, int y)
{
	int y_ret;

	y_ret = y_start;
	while ((ft_strchr(NOTWALL, all->map[y_start][x])
			&& y_start))
		y_start--;
	if (all->map[y_start][x] == '1')
		y_ret--;
	else
		return (error(all, "Unclosed map notwall left back"));
	return (y_ret);
}

int		ft_mapcheck(t_all *all, int y)
{
	int		x;

	while (y < all->y_map_max)
	{
		x = 0;
		while (x < all->x_map_max)
		{
			if (all->map_sp[y][x] != '1' && y == 0)
				return (error(all, "Unclosed map 1"));
			else if (all->map_sp[y][x] != '1' && y == all->y_map_max)
				return (error(all, "Unclosed map 2"));
			else if (all->map_sp[y][x] != '1' && x == 0)
				return (error(all, "Unclosed map 3"));
			else if (all->map_sp[y][x] != '1' && x == all->x_map_max - 1)
				return (error(all, "Unclosed map 4"));
			x++;
		}
		y++;
	}
	return (1);
}