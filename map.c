/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:59:45 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 20:50:50 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_red_square (t_data img, int x_start, int y_start, int size)
{
    int x = x_start;
    int y = y_start;

    while (y++ < size + y_start)
    {
        x = x_start;
        while (x++ < size + x_start)
        {
            my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        }
    }
}
void draw_blue_square (t_data img, int x_start, int y_start, int size)
{
	int x = x_start;
	int y = y_start;

	while (y++ < size + y_start)
	{
		x = x_start;
		while (x++ < size + x_start)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000FF);
		}
	}
}

void big_square(t_all *all, int x, int y)
{


	while (y++ < 1079)
	{
		x = 0;
		while (x++ < 1919)
		{
			my_mlx_pixel_put(all->win, x, y, 0x000000FF);
		}
	}
}