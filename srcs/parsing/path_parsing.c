/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:21:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 19:59:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		trim_path(t_all *all, int y, char *line)
{
	if (all->map[y][0] == 'S' && all->map[y][1] == 'O')
	{
		all->south->path = ft_strtrim(line + 2, " ");
		return (1);
	}
	if (all->map[y][0] == 'W' && all->map[y][1] == 'E')
	{
		all->west->path = ft_strtrim(line + 2, " ");
		return (1);
	}
	if (all->map[y][0] == 'E' && all->map[y][1] == 'A')
	{
		all->east->path = ft_strtrim(line + 2, " ");
		return (1);
	}
	if (all->map[y][0] == 'N' && all->map[y][1] == 'O')
	{
		all->north->path = ft_strtrim(line + 2, " ");
		return (1);
	}
	return (0);
}

int		parse_path_tex(t_all *all)
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
			if (!(line = line_allocation(all->map[y])))
				return (error(all, "Malloc error during texture path parsing"));
			if (trim_path(all, y, line))
				free(line);
		}
		y++;
	}
	return (0);
}

int		parse_path_sprite(t_all *all)
{
	int		y;
	char	*line;
	char	*tmp;
	char	*another_tmp;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'S')
		{
			if (!(line = line_allocation(all->map[y])))
				return (error(all, "Malloc error during sprite path parsing"));
			tmp = line;
			line++;
			another_tmp = all->sprite->path;
			if (!(all->sprite->path = ft_strtrim(line, " ")))
				return (error(all, "Malloc error parse_path_sprite"));
			free(tmp);
			free(another_tmp);
		}
		y++;
	}
	return (0);
}
