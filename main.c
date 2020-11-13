/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 00:03:31 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int fd = open("./maps/map.cub", O_RDONLY);
	t_data  img;
    t_plr plr;
    t_all all;
    t_tex north;
    t_tex south;
    t_tex west;
    t_tex east;
    t_tex sprite;
    t_spr item;
    t_cast cast;
	t_texture tex;

	img.mlx = mlx_init();

	all.map = read_map(fd);
	all.plr = &plr;
	all.img = &img;
	all.north = &north;
	all.west = &west;
	all.south = &south;
	all.east = &east;
	all.sprite = &sprite;
	all.item = &item;
	all.cast = &cast;
	all.tex = &tex;

    game_init(&all);
	all.zbuffer = malloc(sizeof(double) * all.w);
	ft_memset(all.zbuffer, 0, sizeof(double) * all.w);


    img.mlx_win = mlx_new_window(img.mlx, all.w, all.h, "cub");
    img.img = mlx_new_image(img.mlx, all.w, all.h);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
                                 &img.endian);

	sky_floor(&all);
    drawscreen(&all);

    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
    mlx_loop(img.mlx);
}
