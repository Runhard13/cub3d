/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:00:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 14:50:03 by cdrennan         ###   ########.fr       */
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

char *line_allocation (char *map)
{
	char *line;
	int len = 0;
	int i = 0;
	len = (int)ft_strlen(map);
	line = malloc(sizeof(char *) * (len + 1));
	while(map[i])
	{
		line[i] = map[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
