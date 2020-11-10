/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:12:19 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/10 17:05:08 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

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
#define  moveSpeed 0.5
#define rotSpeed 0.1
#define w 640
#define h 480
#define texS 1
#define texN 2
#define	texW 3
#define texE 4

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

typedef struct	s_plr // player and ray
{
	double		posX;
	double		posY;
	double 		dirX;
	double 		dirY;
	double		planeX;
	double		planeY;
	int 		side;
}				  t_plr;

typedef struct	s_tex // все вместе
{
	void    *tex_img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
	char    *path;
	int     tex_width;
	int     tex_height;
}				  t_tex;


typedef struct	s_all // все вместе
{
	t_data		*img;
	t_plr		*plr;
	char 		**map;
	t_tex		*north;
	t_tex		*south;
	t_tex		*east;
	t_tex		*west;
}				  t_all;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press(int keycode, t_all *all);
char	**make_map(t_list **head, size_t size);
char	**read_map (int fd);
void	draw_line (t_all *all, int side, int drawStart, int drawEnd, int x);
void	big_square(t_all *all);
void	drawscreen(t_all *all);
int		find_player (t_all *all);
void	tex_open (t_all *all);
void get_tex_data (t_all *all);
int get_color (t_tex *tex, int x, int y);
int wall_side (int side, double rayDirX, double rayDirY);
void sky_floor(t_all *all);

#endif //CUB3D_CUB3D_H
