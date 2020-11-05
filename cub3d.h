/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:12:19 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/05 20:38:17 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

#  define SCALE 10
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124

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
	float		x;
	float		y;
	float 		pov;
	float 		fov;
	float 		left_ray;
	float 		right_ray;
}				  t_plr;

typedef struct	s_ray // луч
{
	float		x;
	float		y;
	int 		number_of_rays;

}				  t_ray;

typedef struct	s_hit // расстояние до преграды
{
	float		x;
	float		y;
}				  t_hit;




typedef struct	s_all // все вместе
{
	t_data		*win;
	t_plr		*plr;
	char 		**map;
	t_ray		*ray;
	t_hit		*hit;
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

#endif //CUB3D_CUB3D_H
