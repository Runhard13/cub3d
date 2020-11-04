/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:12:19 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 16:05:25 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

# ifndef SCALE
#  define SCALE 50
# endif

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include "minilibx_mms_20200219/mlx.h"

typedef struct  s_data {

	void    	*mlx;
	void    	*mlx_win;
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_data		*win;
	t_plr		*plr;
	char 		**map;
}				  t_all;




void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_red_square (t_data img, int x, int y, int size);
void draw_blue_square (t_data img, int x_start, int y_start, int size);
void draw_player (t_data img, int x_start, int y_start, int size);
int             key_press(int keycode, t_all *all);
void draw(int fd, t_all *all);

#endif //CUB3D_CUB3D_H
