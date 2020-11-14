/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:12:19 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 16:43:53 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include "minilibx_mms_20200219/mlx.h"
# include <math.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define Q 12
# define E 14
# define SPEED 0.5
# define ROT 0.2
# define TEX_S 1
# define TEX_N 2
# define TEX_W 3
# define TEX_E 4

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_plr
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_plr;

typedef struct	s_cast
{
	int 		side;
	double 		raydirx;
	double 		raydiry;
	double 		perp_wall_dist;
	int 		line_h;
	int			step_x;
	int 		step_y;
	double 		side_x;
	double 		side_y;
	double 		delta_x;
	double 		delta_y;
	int 		map_y;
	int 		map_x;

}				t_cast;


typedef struct	s_tex
{
	void		*tex_img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	char		*path;
	int			tex_width;
	int			tex_height;

}				t_tex;

typedef struct	s_texture
{
	double		step;
	double 		wall_x;
	int 		tex_x;
	int 		tex_y;
	double 		tex_pos;
	int 		color;

}				t_texture;

typedef struct	s_spr
{
	int			x;
	int			y;
	int			sprite_count;
	double		sprite_x;
	double 		sprite_y;
	double 		transform_x;
	double 		transform_y;
	int 		sprite_screen_x;
	int 		sprite_h;
	int 		sprite_w;
	int 		draw_start_x;
	int 		draw_start_y;
	int 		draw_end_x;
	int 		draw_end_y;
	double 		inv_det;
	int 		*spr_ord;
	double 		*spr_dist;
	int 		tex_x;
	int 		tex_y;

}				t_spr;

typedef struct	s_all
{
	t_data		*img;
	t_plr		*plr;
	char		**map;
	t_tex		*north;
	t_tex		*south;
	t_tex		*east;
	t_tex		*west;
	t_tex		*sprite;
	t_spr		*item;
	int			w;
	int			h;
	int			floor_color;
	int			sky_color;
	t_cast		*cast;
	t_texture	*tex;
	double 		*zbuffer;
}				t_all;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				key_press(int keycode, t_all *all);
char			**make_map(t_list **head, size_t size);
char			**read_map (int fd);
void			drawscreen(t_all *all);
void			parse_player(t_all *all);
void			tex_open(t_all *all);
void			get_tex_data (t_all *all);
int				get_color(t_tex *tex, int x, int y);
int				wall_side(t_all *all);
void			sky_floor(t_all *all);
void			sprites_open(t_all *all);
void			spr_sort(int *spr_ord, double *spr_dist, int number);
void 			draw_sprite(t_all *all, int *spr_ord, double *spr_dist);
int				parse_resolution(t_all *all);
char			*line_allocation(char *map);
int				parse_color_floor(t_all *all);
int				parse_color_sky(t_all *all);
int				cub_atoi(const char *str);
void			parse_sprite (t_all *all);
int				get_intlen(int n);
int				create_trgb(int t, int r, int g, int b);
void			move_forward (t_all *all);
void			move_back(t_all *all);
void			rot_right(t_all *all);
void			rot_left(t_all *all);
void			strafe_left(t_all *all);
void			strafe_right(t_all *all);
int				parse_path_tex(t_all *all);
int				parse_path_sprite(t_all *all);
void			player_north(t_all *all, int x, int y);
void			player_south(t_all *all, int x, int y);
void			player_west(t_all *all, int x, int y);
void			player_east(t_all *all, int x, int y);
void			game_config(t_all *all);
void			tex_draw(t_all *all, int x, int drawStart, int drawEnd);
void			rays_calc(t_all *all, int x);
void 			preform_dda(t_all *all);
void			step_calc(t_all *all);
void			free_all(t_all *all);
void			destroy_images(t_all *all);
int				error(t_all *all, char *msg);
int				open_fd(t_all *all, char *path);

#endif
