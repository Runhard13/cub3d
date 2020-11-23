/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:05:40 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 13:59:10 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_big_resol(t_all *all)
{
	all->w = (all->w > 1920 ? 1920 : all->w);
	all->h = (all->h > 1080 ? 1080 : all->h);
}

int		get_intlen(int n)
{
	int len;

	len = 1;
	if (n == -2147483648)
		return (10);
	if (n <= 0)
		n = -n;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	eval_resolution(t_all *all, char *line)
{
	line += 1;
	all->w = ft_atoi(line);
	while (*line && *line == ' ')
		line++;
	line += get_intlen(all->w);
	all->h = ft_atoi(line);
}

int		parse_resolution(t_all *all)
{
	int		y;
	char	*line;
	char	*tmp;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'R')
		{
			if (!(line = line_allocation(all->map[y])))
				return (error(all, "Malloc error during resolution parsing"));
			tmp = line;
			eval_resolution(all, line);
			if (!(all->h) || !(all->w))
			{
				free(tmp);
				return (error(all, "Invalid resolution"));
			}
			handle_big_resol(all);
			free(tmp);
			break ;
		}
		y++;
	}
	return (0);
}
