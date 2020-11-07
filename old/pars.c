/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:18:24 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 22:05:34 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

char **read_map (int fd)
{
	char *str = 0;
	t_list *head = 0;
	int amount = 0;

	while(get_next_line(fd, &str))
	{
		ft_lstadd_back(&head, ft_lstnew(str));
		amount++;
		str = NULL;
	}
	ft_lstadd_back(&head, ft_lstnew(str));
	amount++;
	close(fd);
	return (make_map(&head, amount));
}

void draw_map(t_all *all)
{
	int x = 0;
	int y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N')
			{
				all->plr->x = x*SCALE;
				all->plr->y = y*SCALE;
				all->plr->pov = -M_PI/2;
				//draw_blue_square(*all->win, x * SCALE, y * SCALE, SCALE);
				//draw_player(*all->win, all->plr->x * SCALE, all->plr->y * SCALE, SCALE);
				//draw_player_ray(all);
			}
			//if (all->map[y][x] == '1')
			//	draw_red_square(*all->win, x * SCALE, y * SCALE, SCALE);
			//if (all->map[y][x] == '0')
				//draw_blue_square(*all->win, x * SCALE, y * SCALE, SCALE);

			x++;
		}
		y++;
	}
	big_square(all, 0, 0);
	raycaster(all);
	mlx_put_image_to_window(all->win, all->win->mlx_win, all->win->img, 0, 0);
}

void redraw_map(t_all *all)
{
	//int x = 0;
	//int y = 0;
	//while (all->map[y])
	//{ x = 0;
	//	while (all->map[y][x])
	//	{
	//		if (all->map[y][x] == 'N')
	//			draw_blue_square(*all->win, x * SCALE, y * SCALE, SCALE);
		//	if (all->map[y][x] == '1')
	//			draw_red_square(*all->win, x * SCALE, y * SCALE, SCALE);
		//	if (all->map[y][x] == '0')
		//		draw_blue_square(*all->win, x * SCALE, y * SCALE, SCALE);
		//	x++;
	//	}
	//	y++;
//	}
	//draw_player(*all->win, all->plr->x * SCALE, all->plr->y * SCALE, SCALE);
	big_square(all, 0, 0);
	raycaster (all);
	mlx_put_image_to_window(all->win, all->win->mlx_win, all->win->img, 0, 0);
}