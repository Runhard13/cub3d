/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 19:52:39 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int main()
{

	int fd = open("./maps/map.cub", O_RDONLY);
	t_data  img;
    t_plr plr;
    t_all all;


    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 1980, 1620, "2d map");
    img.img = mlx_new_image(img.mlx, 1980, 1620);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    all.plr = &plr;
    all.win = &img;
    all.map = read_map(fd);

    //what to draw - start

	fd = open("./maps/map.cub", O_RDONLY);
    draw_map(&all);

    // what to draw - end

    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
    mlx_loop(img.mlx);
}