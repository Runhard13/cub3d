/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:49:51 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/22 21:36:26 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int if_space(t_all *all, int x, int y)
{
	while (all->map[y][x] == ' ' && y < all->y_map_max)
		y++;
	if (all->map[y][x] == '1')
		x++;
	else if (y == all->y_map_max)
		x++;
	else
		return (error(all, "Unclosed map"));
	return (x);
}

int if_notwall(t_all *all, int x, int y)
{
	while ((ft_strchr(NOTWALL, all->map[y][x])
			&& y < all->y_map_max))
		y++;
	if (all->map[y][x] == '1')
		x++;
	else
		return (error(all, "Unclosed map"));
	return (x);
}

int if_space_back(t_all *all, int x, int y, int y_start)
{
	while (all->map[y_start][x] == ' ' && y_start > y)
		y_start--;
	if (all->map[y_start][x] == '1')
		x++;
	else if (y_start == y)
		x++;
	else
		return (error(all, "Unclosed map"));
	return (x);
}

int if_notwall_back(t_all *all, int x, int y, int y_start)
{
	while ((ft_strchr(NOTWALL, all->map[y_start][x])
			&& y_start > y))
		y_start--;
	if (all->map[y_start][x] == '1')
		x++;
	else
		return (error(all, "Unclosed map"));
	return (x);
}

int if_space_left(t_all *all, int x, int y)
{
	int y_ret;

	y_ret = y;
	while (all->map[y][x] == ' ' && y < all->y_map_max)
		y++;
	if (all->map[y][x] == '1')
		y_ret++;
	else if (y == all->y_map_max)
		y_ret++;
	else
		return (error(all, "Unclosed map left"));
	return (y_ret);
}