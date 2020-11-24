/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:05:22 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 21:01:32 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		error(t_all *all, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_all(all);
	return (0);
}

int		open_fd(t_all *all, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4 || !(ft_strrchr(path, '.')))
		error_wo_all("Invalid map file");
	if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4) == 0)
		fd = open(path, O_RDONLY);
	else
		error_wo_all("Invalid map file");
	if (fd == -1)
	{
		error(all, "Invalid fd");
	}
	return (fd);
}

int		error_wo_all(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(0);
}

int		error_map(t_all *all, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_tab(all->map, all->map_size);
	exit(0);
}
