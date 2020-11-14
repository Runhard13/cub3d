/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:21:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 18:26:25 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_path_tex(t_all *all)
{
	int		y;
	char	*line;

	y = 0;
	while (all->map[y])
	{
		if ((all->map[y][0] == 'N' && all->map[y][1] == 'O') ||
			(all->map[y][0] == 'S' && all->map[y][1] == 'O') ||
			(all->map[y][0] == 'W' && all->map[y][1] == 'E') ||
			(all->map[y][0] == 'E' && all->map[y][1] == 'A'))
		{
			line = line_allocation(all->map[y]);
			line += 2;
		}
		if (all->map[y][0] == 'S' && all->map[y][1] == 'O')
			all->south->path = ft_strtrim(line, " ");
		if (all->map[y][0] == 'W' && all->map[y][1] == 'E')
			all->west->path = ft_strtrim(line, " ");
		if (all->map[y][0] == 'E' && all->map[y][1] == 'A')
			all->east->path = ft_strtrim(line, " ");
		if (all->map[y][0] == 'N' && all->map[y][1] == 'O')
			all->north->path = ft_strtrim(line, " ");
		y++;
	}
}

void	parse_path_sprite(t_all *all)
{
	int		y;
	char	*line;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'S')
		{
			line = line_allocation(all->map[y]);
			line += 1;
			all->sprite->path = ft_strtrim(line, " ");
		}
		y++;
	}
}
