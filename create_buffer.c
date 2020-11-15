/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:17:57 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/15 23:22:53 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_buffers (t_all *all)
{

	if (!(all->sprites_cc = malloc(sizeof(t_spr_count) * all->item->sprite_count)))
		return (error(all, "Sprite_dist array allocation error"));
	ft_memset(all->sprites_cc, 0, (sizeof(t_spr_count) * all->item->sprite_count));
	if (!(all->zbuffer = malloc(sizeof(double) * all->w)))
		return (error(all, "ZBuffer allocation error"));
	ft_memset(all->zbuffer, 0, sizeof(double) * all->w);
	return(1);
}