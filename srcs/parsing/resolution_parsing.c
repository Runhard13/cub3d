/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:05:40 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/21 20:58:17 by cdrennan         ###   ########.fr       */
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

int		cub_atoi(const char *str)
{
	size_t	result;
	int		i;

	i = 0;
	result = 0;
	while ((str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	return ((int)result);
}

void	eval_resolution(t_all *all, char *line)
{
	line += 1;
	all->w = cub_atoi(line);
	while (*line && *line == ' ')
		line++;
	line += get_intlen(all->w);
	all->h = cub_atoi(line);
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
