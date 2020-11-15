/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:37:42 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/15 20:03:45 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int			check_first_horizontal(t_all *all, int y)
{
	int x;

	x = 0;
	while (all->map[y][x])
	{
		if (!((all->map[y][x] == '1' || all->map[y][x] == ' ')))
			if(all->map[y + 1][x])
				return(error(all, "Unclosed map"));
		x++;
	}
	return (1);
}

int			check_last_horizontal(t_all *all, int y)
{
	int x;

	x = 0;
	while (all->map[y][x])
	{
		if (!((all->map[y][x] == '1' || all->map[y][x] == ' ')))
			if(all->map[y - 1][x])
				return(error(all, "Unclosed map"));
		x++;
	}
	return (1);
}

int			check_borders(t_all *all, int y)
{
	char *line;
	if(!(line = line_allocation(all->map[y])))
		return(error(all, "Malloc error during line allocation"));
	ft_strtrim(line, " ");
	if (!(line[0] == '1' && line[ft_strlen(line) - 1] == '1'))
		return(error(all, "Unclosed map"));
	return (1);
}

int	map_check(t_all *all)
{
	int y;

	y = 0;
	while (find_char(CONFIG_CHR, all->map[y][0]))
		y++;
	check_forbidden(all, y);
	check_first_horizontal(all, y);
	while (all->map[++y])
		check_borders(all, y);
	check_last_horizontal(all, y - 1);
	return (1);
}