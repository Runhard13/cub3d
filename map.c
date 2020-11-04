/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:59:45 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 16:58:05 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void draw(int fd, t_all *all)
{

    char *line = NULL;
    int x = 0;
    int y = 0;
    while (get_next_line(fd, &line))
    {
        while (*(line + x))
        {
            if (*(line + x) == 'N')
            {
                all->plr->x = x;
                all->plr->y = y;
                draw_player(*all->win, all->plr->x*SCALE, all->plr->y*SCALE, SCALE);

            }
            if (*(line + x) == '1')
                draw_red_square(*all->win, x*SCALE, y*SCALE, SCALE);
            if (*(line + x) == '0')
                draw_blue_square(*all->win, x*SCALE, y*SCALE, SCALE);

            x++;
        }
        y++;
        x = 0;
    }
	while (*(line + x))
	{
		if (*(line + x) == 'N')
		{
			all->plr->x = x;
			all->plr->y = y;
			draw_player(*all->win, all->plr->x*SCALE, all->plr->y*SCALE, SCALE);

		}
		if (*(line + x) == '1')
			draw_red_square(*all->win, x*SCALE, y*SCALE, SCALE);
		if (*(line + x) == '0')
			draw_blue_square(*all->win, x*SCALE, y*SCALE, SCALE);

		x++;

	}
}