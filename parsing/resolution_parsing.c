/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:05:40 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 19:28:16 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	parse_resolution(t_all *all)
{
	int		y;
	char	*line;

	y = 0;
	while (all->map[y])
	{
		if (all->map[y][0] == 'R')
		{
			if(!(line = line_allocation(all->map[y])))
				return(error(all, "Malloc error during resolution parsing"));
			line += 1;
			if(!(all->w = cub_atoi(line)))
				return(error(all, "Invalid resolution"));
			while (*line && *line == ' ')
				line++;
			line += get_intlen(all->w);
			if(!(all->h = cub_atoi(line)))
				return(error(all, "Invalid resolution"));
			all->w = (all->w > 1920 ? 1920 : all->w);
			all->h = (all->h > 1080 ? 1080 : all->h);
			break ;
		}
		y++;
	}
	return (0);
}