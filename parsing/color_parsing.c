/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:11:22 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/18 22:49:15 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_color (int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || r > 255) || (b < 0 || r > 255))
		return (0);
	return (1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	parse_color_floor(t_all *all)
{
	int		y;
	char	*line;
	char 	*tmp;
	int		r;
	int		g;
	int		b;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'F')
		{
			if(!(line = line_allocation(all->map[y])))
				return(error(all, "Malloc error during floor color parsing"));
			tmp = line;
			line += 1;
			r = cub_atoi(line);
			while (*line && (*line == ' ' || *line == ','))
				line++;
			g = cub_atoi(line + get_intlen(r));
			while (*line && (*line == ' ' || *line == ','))
				line++;
			b = cub_atoi(line + get_intlen(r) + get_intlen(g));
			if (!(check_color(r, g, b)))
				return(error(all, "Invalid floor color"));
			all->floor_color = create_trgb(0, r, g, b);
			free(tmp);
		}
		y++;
	}
	return (0);
}

int	parse_color_sky(t_all *all)
{
	int		y;
	char	*line;
	char 	*tmp;
	int		r;
	int		g;
	int		b;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'C')
		{
			if(!(line = line_allocation(all->map[y])))
				return(error(all, "Malloc error during sky color parsing"));
			tmp = line;
			line += 1;
			r = cub_atoi(line);
			while (*line && (*line == ' ' || *line == ','))
				line++;
			g = cub_atoi(line + get_intlen(r));
			while (*line && (*line == ' ' || *line == ','))
				line++;
			b = cub_atoi(line + get_intlen(r) + get_intlen(g));
			if (!(check_color(r, g, b)))
				return(error(all, "Invalid sky color"));
			all->sky_color = create_trgb(0, r, g, b);
			free(tmp);
		}
		y++;
	}
	return (0);
}
