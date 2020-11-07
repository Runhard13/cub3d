/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:12:19 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 21:00:59 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

#define SCALE 5
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define Q 12
#define E 14
#define  SPEED 4

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include "minilibx_mms_20200219/mlx.h"
#include <math.h>

typedef struct  s_data // картинка
{

	void    	*mlx;
	void    	*mlx_win;
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_plr // игрок
{
	double		x;
	double		y;
	double 		pov;
	double 		fov;
	double		left_ray;
	double		right_ray;
	double 		ray_x;
	double 		ray_y;
}				  t_plr;



typedef struct	s_all // все вместе
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
char	**make_map(t_list **head, int size);
char **read_map (int fd);
void draw_map(t_all *all);
void redraw_map(t_all *all);
void raycaster (t_all *all);
void draw_player_ray (t_all *all);
void draw_line (t_all *all, double dist, int i);
int rounding (int dist);
void big_square(t_all *all, int x_start, int y_start);

#endif //CUB3D_CUB3D_H
