/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:17:57 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/19 23:33:27 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_buffers (t_all *all)
{

	if (!(all->item->spr_dist = malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite_dist array allocation error"));
	if (!(all->item->spr_ord = malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite_ord array allocation error"));
	if (!(all->zbuffer = malloc(sizeof(t_all) * all->w)))
		return (error(all, "ZBuffer allocation error"));
	if (!(all->ss = malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite coord array alloc error"));

	ft_memset(all->item->spr_ord, 0, (sizeof(t_all) * all->item->sprite_count));
	ft_memset(all->item->spr_dist, 0, (sizeof(t_all) * all->item->sprite_count));
	ft_memset(all->zbuffer, 0, sizeof(t_all) * all->w);
	ft_memset(all->ss, 0, sizeof(t_all) * all->item->sprite_count);
	return(1);
}