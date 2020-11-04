/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:01:29 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 15:28:49 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void draw_player (t_data img, int x_start, int y_start, int size)
{
	int x = x_start;
	int y = y_start;

	while (y++ < size + y_start)
	{
		x = x_start;
		while (x++ < size + x_start)
		{
			my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		}
	}
}