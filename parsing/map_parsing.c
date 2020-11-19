/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:00:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/19 13:45:49 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**make_map(t_list **head, size_t size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		return (NULL);
	tmp = *head;
	i = -1;
	while (tmp)
	{
		map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(head, &free);
	return (map);
}

char	**read_map(int fd)
{
	char	*str;
	t_list	*head;
	size_t	amount;

	str = NULL;
	head = NULL;
	amount = 0;
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

char	*line_allocation(char *map)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(map);
	if (!(line = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (map[i])
	{
		line[i] = map[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
