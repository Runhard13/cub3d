/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aaaaaaaaaa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:40:55 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 13:42:12 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void add_spaces (t_all *all, char *line, int num, int i)
{
	char *dst;
	int j;

	j = 0;
	dst = ft_calloc(1, num + 1);

	while (line[j])
	{
		dst[j] = line[j];
		j++;
	}
	while (j < num)
	{
		dst[j] = ' ';
		j++;
	}
	dst[j] = '\0';

	all->map_sp[i] = dst;

}

void make_space_map (t_all *all, int y)
{
	char *line;
	int num;
	int i;

	i = 0;
	while (all->map[y])
	{
		line = line_allocation(all->map[y]);
		num = all->x_map_max;
		if (num > 0)
			add_spaces(all, line, num, i);
		i++;
		y++;
	}
}


int		mapcheck(t_all *all)
{
	int		x;
	int		y;

	y = 0;

	while (all->map_sp[y])
	{
		x = 0;
		while (all->map_sp[y][x])
		{
			if (!(all->map_sp[y][x] == '1' || all->map_sp[y][x] == ' ') && y == 0)
				return (error(all, "Unclosed map first line"));
			else if (!(all->map_sp[y][x] == '1' || all->map_sp[y][x] == ' ') && y == all->y_map_max)
				return (error(all, "Unclosed map last line"));

			else if (!(all->map_sp[y][x] == '1' || all->map_sp[y][x] == ' ') && x == 0)
				return (error(all, "Unclosed map left border"));
			else if (!(all->map_sp[y][x] == '1' || all->map_sp[y][x] == ' ') && y == all->y_map_max)
				return (error(all, "Unclosed map right border"));

			else if (ft_strchr(NOTWALL, all->map_sp[y][x]))
				if (all->map_sp[y + 1][x] == ' ' || all->map_sp[y][x + 1] == ' ' ||
				all->map_sp[y - 1][x] == ' ' || all->map_sp[y][x - 1] == ' ')
					return (error(all, "Unclosed map!!!!!!!"));
			x++;
		}
		y++;
	}
	return (1);
}
