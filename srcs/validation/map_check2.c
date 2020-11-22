/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:37:42 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/22 19:51:24 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int		find_char(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

int		check_first_horizontal(t_all *all, int y)
{
	int x;
	int pos;
	int len;
	int len_prev;

	len_prev = 0;
	while (all->map[y])
	{
		//len = find_len_x(all, y);
		//if (len > len_prev)
		//	x = len_prev;
		//else
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '1')
			{
				x++;
			}
			else if (all->map[y][x] == ' ')
			{
				pos = y;
				while (all->map[pos][x] == ' ' && pos < all->y_map_max)
					pos++;
				if (all->map[pos][x] == '1')
					x++;
				if (pos == all->y_map_max)
					x++;
				else
					return(error(all, "Unclosed map"));
			}
			else if (ft_strchr(NOTWALL, all->map[y][x]))
			{
				pos = y;
				while ((ft_strchr(NOTWALL, all->map[pos][x]) && pos < all->y_map_max))
					pos++;
				if (all->map[pos][x] == '1')
					x++;
				else
					return(error(all, "Unclosed map"));
			}
		}
		y++;
		//len_prev = len;



	}
	return (0);
}

int		check_last_horizontal(t_all *all, int y)
{
	return (0);
}

int		check_borders(t_all *all, int y)
{
	char *line;
	char *tmp;
	char *another_tmp;

	if (!(line = line_allocation(all->map[y])))
		return (error(all, "Malloc error during line allocation"));
	tmp = line;
	another_tmp = ft_strtrim(line, " ");
	if (!(line[0] == '1' && line[ft_strlen(line) - 1] == '1'))
	{
		free(tmp);
		return (error(all, "Unclosed map"));
	}
	free(tmp);
	free(another_tmp);
	return (1);
}

int		map_check(t_all *all)
{
	int y;

	y = 0;
	while (find_char(CONFIG_CHR, all->map[y][0]))
		y++;
	find_map_max (all, y);
	check_forbidden(all, y);
	check_first_horizontal(all, y);
	while (all->map[++y])
		check_borders(all, y);
	check_last_horizontal(all, y - 1);
	return (1);
}
