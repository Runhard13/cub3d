/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:59:44 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 23:13:31 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line (t_all *all, double height, int x)
{
	int start = -height / 2 + h / 2;
	if (start < 0)
		start = 0;
	int end = height / 2 + h / 2;
	if (end > h)
		end = h - 1;
	while (start < end)
	{
		my_mlx_pixel_put(all->img, x, start, 0x000000FF);
		start++;
	}
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
			my_mlx_pixel_put(all->img, x, y, 0xFFFFFF);
		}
	}
}