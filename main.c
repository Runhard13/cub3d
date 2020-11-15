/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 19:34:33 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*path;

	t_all all;
	ft_memset(&all, 0, sizeof(t_all));

	if (argc > 3 || argc == 1)
		return (error(&all, "Wrong number of arguments"));
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 6)) && ft_strlen(argv[2]) == 6)
		all.screenshot = 1;
	path = argv[1];
	fd = open_fd(&all, path);

	t_data img;
    t_plr plr;
    t_tex north;
    t_tex south;
    t_tex west;
    t_tex east;
    t_tex sprite;
    t_spr item;
    t_cast cast;
	t_texture tex;

	ft_memset(&img, 0, sizeof(t_data));
	ft_memset(&plr, 0, sizeof(t_plr));
	ft_memset(&north, 0, sizeof(t_tex));
	ft_memset(&south, 0, sizeof(t_tex));
	ft_memset(&west, 0, sizeof(t_tex));
	ft_memset(&east, 0, sizeof(t_tex));
	ft_memset(&sprite, 0, sizeof(t_tex));
	ft_memset(&item, 0, sizeof(t_spr));
	ft_memset(&cast, 0, sizeof(t_cast));
	ft_memset(&tex, 0, sizeof(t_texture));


	if(!(img.mlx = mlx_init()))
		return (error(&all, "MLX can't init"));

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

    game_config(&all);
    validate_map (&all);

	if (!(all.item->spr_dist = malloc(sizeof(double) * all.item->sprite_count)))
		return (error(&all, "Sprite_dist array allocation error"));
	if (!(all.item->spr_ord = malloc(sizeof(int) * all.item->sprite_count)))
		return (error(&all, "Sprite_ord array allocation error"));
	ft_memset(all.item->spr_ord, 0, (sizeof(int) * all.item->sprite_count));
	ft_memset(all.item->spr_dist, 0, (sizeof(int) * all.item->sprite_count));
	if (!(all.zbuffer = malloc(sizeof(double) * all.w)))
		return (error(&all, "ZBuffer allocation error"));
	ft_memset(all.zbuffer, 0, sizeof(double) * all.w);


    if(!(img.mlx_win = mlx_new_window(img.mlx, all.w, all.h, "cub")))
		return (error(&all, "MLX can't create new window"));
    if(!(img.img = mlx_new_image(img.mlx, all.w, all.h)))
		return (error(&all, "MLX can't create new image"));
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
                                 &img.endian);

	sky_floor(&all);
    drawscreen(&all);

    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
	mlx_hook(img.mlx_win, 17, 1L << 17, free_all, &all);
    mlx_loop(img.mlx);
}
