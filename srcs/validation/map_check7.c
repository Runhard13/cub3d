/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:16:37 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 13:15:16 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int  count_check_columns(char const *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1')
			j++;
		else if (line[i] != ' ')
			return (0);
		i++;
	}
	return (j);
}

int check_top_bottom_borders(t_all *all, int y)
{
	int		first_line;
	int		last_line;
	char 	*first;
	char	*last;

	first = line_allocation(all->map_sp[y]);
	last = line_allocation(all->map_sp[all->y_map_max]);

	first_line = count_check_columns(first);

	if (last)
		last_line = count_check_columns(last);
	else
		last_line = 0;
	if (first_line == last_line)
		return (first_line);
	return (0);
}

int
check_left_right_borders(t_all *all, int y)
{
	int				i;
	int				first;
	int				last;
	char *line;

	i = 0;
	while (all->map_sp[y])
	{
		line = line_allocation(all->map_sp[y]);
		first = 0;
		while (line[first] == ' ')
			first++;
		last = ft_strlen(line) - 1;
		while (last > 0 && last == ' ')
			last--;
		if (last <= 1 || line[first] != '1' || line[last] != '1')
			return(error(all, "Bad map_lr_borders"));
		i++;
		y++;
	}
	return (i);
}

int check_valid(t_all *all, int y, int column)
{
	int	i;
	int	col;

	while (all->map_sp[y])
	{
		i = 0;
		col = 0;
		while (all->map_sp[y][i])
		{
			if (all->map_sp[y][i++] != ' ')
				col++;
		}
		if (col != column)
			return(error(all, "Bad map_valid"));
		y++;
	}
	return (1);
}


int map_ccceck(t_all *all, int y)
{
	int col;
	int row;

	col = check_top_bottom_borders(all, y);
	row = check_left_right_borders(all, y);

	if ((col <= 2 || row <= 2 || !check_valid(all, y, col)))
		return(error(all, "bad map col_row"));
	return (1);
}