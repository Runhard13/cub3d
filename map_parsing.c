/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:00:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/11 21:06:59 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

char	**make_map(t_list **head, size_t size)
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
	size_t amount = 0;

	while (get_next_line(fd, &str))
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

void parse_player_and_sprite (t_all *all)
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
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 0;
				all->plr->dirY = -1;
				all->plr->planeY = 0;
				all->plr->planeX = 0.66;
				x++;
			}
			if (all->map[y][x] == 'W')
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = -1;
				all->plr->dirY = 0;
				all->plr->planeY = -0.66;
				all->plr->planeX = 0;
				x++;
			}
			if (all->map[y][x] == 'S')
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 0;
				all->plr->dirY = 1;
				all->plr->planeY = 0;
				all->plr->planeX = -0.66;
				x++;
			}
			if (all->map[y][x] == 'E')
			{
				all->plr->posX = x + 0.5;
				all->plr->posY = y + 0.5;
				all->plr->dirX = 1;
				all->plr->dirY = 0;
				all->plr->planeY = 0.66;
				all->plr->planeX = 0;
				x++;
			}
			if (all->map[y][x] == '2')
			{
				all->item->x = x;
				all->item->y = y;
				all->item->sprite_count++;
				x++;
			}
			else
				x++;
		}

		y++;
	}
}

