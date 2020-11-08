/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:59:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/08 19:14:03 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line (t_all *all, int side, int drawStart, int drawEnd, int x)
{
	int color;
	if (side == 0)
		color = 0x7076c7;
	else
		color = 0x5c60a1;
	while (drawStart++ < drawEnd)
		my_mlx_pixel_put(all->img, x, drawStart, color);

}

void big_square(t_all *all)
{
	int x = 0;
	int y = 0;
	while (y++ < (h-1))
	{
		x = 0;
		while (x++ < (w-1))
		{
			my_mlx_pixel_put(all->img, x, y, 0x030303);
		}
	}
}