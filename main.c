/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/01 22:25:14 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
    //map parsing
    int fd;
    char **map;

    fd = open("./maps/map.cub", O_RDONLY);
    map = map_read(fd);

    //map printing


    //2d map drawing
    void    *mlx;
    void    *mlx_win;
    t_data  img;


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 480, "2d map");
    img.img = mlx_new_image(mlx, 640, 480);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    //what to draw - start
    int x = 0;
    int y = 0;
    while (map[y][x])
    {
        while (map[y][x])
        {
            if (map[y][x] == '1')
            {
                draw_blue_square(img, x*50, y*50, 50);
                write(1, &map[y][x], 1);
            }

            if (map[y][x] == '0')
            {
                draw_red_square(img, x*50, y*50, 50);
                write(1, &map[y][x], 1);
            }
            x++;
        }
        y++;
        //x = 0;
        write(1,"\n", 1);
    }
    // what to draw - end

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}