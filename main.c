/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 01:04:38 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int main()
{
    //map parsing






    //2d map drawing
    void    *mlx;
    void    *mlx_win;
    t_data  img;


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1680, "2d map");
    img.img = mlx_new_image(mlx, 1920, 1680);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    //what to draw - start
    int fd;
    char *line = NULL;

    fd = open("./maps/map.cub", O_RDONLY);
    int x = 0;
    int y = 0;
    while (get_next_line(fd, &line))
    {
        while (*(line + x))
        {
            if (*(line + x) == '1')
                draw_blue_square(img, x*50, y*50, 50);
            if (*(line + x) == '0')
                draw_red_square(img, x*50, y*50, 50);
            if (*(line + x) == ' ')
                continue;
            x++;
        }
        y++;
        x = 0;
    }
    // what to draw - end

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}