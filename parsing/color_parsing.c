/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:11:22 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 16:08:02 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	parse_color_floor(t_all *all)
{
	int		y;
	char	*line;
	int		r;
	int		g;
	int		b;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'F')
		{
			line = line_allocation(all->map[y]);
			line += 1;
			r = cub_atoi(line);
			while (*line && (*line == ' ' || *line == ','))
				line++;
			g = cub_atoi(line + get_intlen(r));
			while (*line && (*line == ' ' || *line == ','))
				line++;
			b = cub_atoi(line + get_intlen(r) + get_intlen(g));
			all->floor_color = create_trgb(0, r, g, b);
		}
		y++;
	}
}

void	parse_color_sky(t_all *all)
{
	int		y;
	char	*line;
	int		r;
	int		g;
	int		b;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'C')
		{
			line = line_allocation(all->map[y]);
			line += 1;
			r = cub_atoi(line);
			while (*line && (*line == ' ' || *line == ','))
				line++;
			g = cub_atoi(line + get_intlen(r));
			while (*line && (*line == ' ' || *line == ','))
				line++;
			b = cub_atoi(line + get_intlen(r) + get_intlen(g));
			all->sky_color = create_trgb(0, r, g, b);
		}
		y++;
	}
}
