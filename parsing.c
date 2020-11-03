/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:35:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/10/31 22:00:12 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **make_map(t_list **head, int size)
{
    char **map = ft_calloc(size + 1, sizeof(char*));
    int i = -1;

    t_list *tmp = *head;
    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next;
    }

    return (map);
}

char **map_read (int fd)
{
    char *line = NULL;
    t_list *head = NULL;

    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&head, ft_lstnew(line));
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    return (make_map(&head, ft_lstsize(head)));

}