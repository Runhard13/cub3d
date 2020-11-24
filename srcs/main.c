/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 19:09:50 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*path;
	t_all	all;
	t_data	img;

	ft_memset(&all, 0, sizeof(t_all));
	ft_memset(&img, 0, sizeof(t_data));
	all.img = &img;
	check_args(&all, argc, argv);
	path = argv[1];
	fd = open_fd(&all, path);
	all.map = read_map(fd, &all);
	if (!(img.mlx = mlx_init()))
		return (error_map(&all, "MLX can't init"));
	init_params(&all);
	if (!(img.mlx_win = mlx_new_window(img.mlx, all.w, all.h, "cub")))
		return (error(&all, "MLX can't create new window"));
	if (!(img.img = mlx_new_image(img.mlx, all.w, all.h)))
		return (error(&all, "MLX can't create new image"));
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	draw_all(&all);
	mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
	mlx_hook(img.mlx_win, 17, 1L << 17, free_all, &all);
	mlx_loop(img.mlx);
}
