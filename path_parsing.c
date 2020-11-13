/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:21:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 15:04:12 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_path (t_all *all)
{
	int y = 0;
	char *line = 0;

	while (all->map[y])
	{

		if (all->map[y][0] == 'N' && all->map[y][1] == 'O')
		{
			line = line_allocation(all->map[y]);
			line += 2;
			all->north->path = ft_strtrim(line, " ");
		}
		if (all->map[y][0] == 'S' && all->map[y][1] == 'O')
		{
			line = line_allocation(all->map[y]);
			line += 2;
			all->south->path = ft_strtrim(line, " ");
		}
		if (all->map[y][0] == 'W' && all->map[y][1] == 'E')
		{
			line = line_allocation(all->map[y]);
			line += 2;
			all->west->path = ft_strtrim(line, " ");
		}
		if (all->map[y][0] == 'E' && all->map[y][1] == 'A')
		{
			line = line_allocation(all->map[y]);
			line += 2;
			all->east->path = ft_strtrim(line, " ");
		}
		if (all->map[y][0] == 'S')
		{
			line = line_allocation(all->map[y]);
			line += 1;
			all->sprite->path = ft_strtrim(line, " ");
		}
		y++;
	}
}