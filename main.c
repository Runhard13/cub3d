/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 15:45:13 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int main()
{


    //2d map drawing
    t_data  img;
    t_plr plr;
    t_all all;

    int fd;

    fd = open("./maps/map.cub", O_RDONLY);




    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 1920, 1680, "2d map");
    img.img = mlx_new_image(img.mlx, 1920, 1680);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    all.plr = &plr;
    all.win = &img;

    //what to draw - start

    draw(fd, all);

    // what to draw - end

    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);

    mlx_loop(img.mlx);
}