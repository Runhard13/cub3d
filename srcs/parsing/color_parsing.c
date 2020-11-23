/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:11:22 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/22 12:07:43 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_color(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || r > 255) || (b < 0 || r > 255))
		return (0);
	return (1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	find_rgb(t_all *all, char *line)
{
	all->rgb->r = ft_atoi(line);
	while (*line && (*line == ' ' || *line == ','))
		line++;
	all->rgb->g = ft_atoi(line + get_intlen(all->rgb->r) + 1);
	while (*line && (*line == ' ' || *line == ','))
		line++;
	all->rgb->b = ft_atoi(line + get_intlen(all->rgb->r) +
			get_intlen(all->rgb->g) + 3);
}

int		parse_color_floor(t_all *all)
{
	int		y;
	char	*line;
	char	*tmp;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'F')
		{
			if (!(line = line_allocation(all->map[y])))
				return (error(all, "Malloc error during floor color parsing"));
			tmp = line;
			line += 1;
			find_rgb(all, line);
			if (!(check_color(all->rgb->r, all->rgb->g, all->rgb->b)))
				return (error(all, "Invalid floor color"));
			all->floor_color = create_trgb(0, all->rgb->r,
					all->rgb->g, all->rgb->b);
			free(tmp);
		}
		y++;
	}
	return (0);
}

int		parse_color_sky(t_all *all)
{
	int		y;
	char	*line;
	char	*tmp;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'C')
		{
			if (!(line = line_allocation(all->map[y])))
				return (error(all, "Malloc error during sky color parsing"));
			tmp = line;
			line += 1;
			find_rgb(all, line);
			if (!(check_color(all->rgb->r, all->rgb->g, all->rgb->b)))
				return (error(all, "Invalid sky color"));
			all->sky_color = create_trgb(0, all->rgb->r,
					all->rgb->g, all->rgb->b);
			free(tmp);
		}
		y++;
	}
	return (0);
}
