/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 16:39:03 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void drawscreen(t_all *all)
{
	int x = 0;
	double z_buf[all->w];
	//arrays used to sort the sprites
	int spr_ord[all->item->sprite_count];
	double spr_dist[all->item->sprite_count];

	while (x++ < all->w)
	{
		double cameraX = 2 * x / (double) all->w - 1; //x-coordinate in camera space
		double raydirx = all->plr->dirx + all->plr->planex * cameraX;
		double raydiry = all->plr->diry + all->plr->planey * cameraX;
		//which box of the map we're in
		int mapX = (int) (all->plr->posx);
		int mapY = (int) (all->plr->posy);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / raydirx);
		double deltaDistY = fabs(1 / raydiry);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (raydirx < 0)
		{
			stepX = -1;
			sideDistX = (all->plr->posx - mapX) * deltaDistX;
		} else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - all->plr->posx) * deltaDistX;
		}
		if (raydiry < 0)
		{
			stepY = -1;
			sideDistY = (all->plr->posy - mapY) * deltaDistY;
		} else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - all->plr->posy) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (all->map[mapY][mapX] == '1') hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - all->plr->posx + (1 - stepX) / 2.0) / raydirx;
		else perpWallDist = (mapY - all->plr->posy + (1 - stepY) / 2.0) / raydiry;

		//Calculate height of line to draw on screen
		int lineHeight = (int) (all->h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + all->h / 2;
		if (drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + all->h / 2;
		if (drawEnd >= all->h)drawEnd = all->h - 1;

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = all->plr->posy + perpWallDist * raydiry;
		else wallX = all->plr->posx + perpWallDist * raydirx;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int) (wallX * (double) (all->north->tex_width));
		if (side == 0 && raydirx > 0) texX = all->north->tex_width - texX - 1;
		if (side == 1 && raydiry < 0) texX = all->north->tex_width - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * all->north->tex_height / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - all->h / 2 + lineHeight / 2) * step;

		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int) texPos & (all->north->tex_height - 1);
			texPos += step;
			int color;
			if (wall_side(side, raydirx, raydiry) == TEX_S)
				color = get_color(all->south, texX, texY);
			if (wall_side(side, raydirx, raydiry) == TEX_N)
				color = get_color(all->north, texX, texY);
			if (wall_side(side, raydirx, raydiry) == TEX_E)
				color = get_color(all->east, texX, texY);
			if (wall_side(side, raydirx, raydiry) == TEX_W)
				color = get_color(all->west, texX, texY);
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			//if(side == 1) color = (color >> 1) & 8355711;
			my_mlx_pixel_put(all->img, x, y, color);
		}
		//draw_line(all, side, drawStart, drawEnd, x);
		//SET THE z_buf FOR THE SPRITE CASTING
		z_buf[x] = perpWallDist; //perpendicular distance is used
	}
	draw_sprite(all, spr_ord, spr_dist, z_buf);
	mlx_put_image_to_window(all->img, all->img->mlx_win, all->img->img, 0, 0);
}

void draw_sprite(t_all *all, int *spr_ord, double *spr_dist, double *z_buf)
{

	//SPRITE CASTING
	//sort sprites from far to close
	for (int i = 0; i < all->item->sprite_count; i++)
	{
		spr_ord[i] = i;
		spr_dist[i] = ((all->plr->posx - all->item[i].x) * (all->plr->posx - all->item[i].x) +
							 (all->plr->posy - all->item[i].x) *
							 (all->plr->posy - all->item[i].x)); //sqrt not taken, unneeded
	}
	spr_sort(spr_ord, spr_dist, all->item->sprite_count);

	//after sorting the sprites, do the projection and draw them
	for (int i = 0; i < all->item->sprite_count; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = all->item[spr_ord[i]].x - all->plr->posx;
		double spriteY = all->item[spr_ord[i]].y - all->plr->posy;

		//transform sprite with the inverse camera matrix
		// [ planex   dirx ] -1                                       [ diry      -dirx ]
		// [               ]       =  1/(planex*diry-dirx*planey) *   [                 ]
		// [ planey   diry ]                                          [ -planey  planex ]

		double invDet = 1.0 / (all->plr->planex * all->plr->diry -
							   all->plr->dirx * all->plr->planey); //required for correct matrix multiplication

		double transformX = invDet * (all->plr->diry * spriteX - all->plr->dirx * spriteY);
		double transformY = invDet * (-all->plr->planey * spriteX + all->plr->planex *
																	spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int)((all->w / 2) * (1 + transformX / transformY));

		//calculate height of the sprite on screen
		int spriteHeight = abs(
				(int) (all->h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + all->h / 2;
		if (drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + all->h / 2;
		if (drawEndY >= all->h) drawEndY = all->h - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int) (all->h / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= all->w) drawEndX = all->w - 1;

		//loop through every vertical stripe of the sprite on screen
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX =
					(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * all->sprite->tex_width / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) z_buf, with perpendicular distance
			if (transformY > 0 && stripe > 0 && stripe < all->w && transformY < z_buf[stripe])
				for (int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y) * 256 - all->h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * all->sprite->tex_height) / spriteHeight) / 256;
					int color = get_color(all->sprite, texX, texY); //get current color from the texture
					if ((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(all->img, stripe, y,
										 color); //paint pixel if it isn't black, black is the invisible color
				}
		}
	}
}

int main()
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

	img.mlx = mlx_init();

    all.plr = &plr;
	all.img = &img;
	all.north = &north;
	all.west = &west;
	all.south = &south;
	all.east = &east;
	all.sprite = &sprite;
	all.item = &item;
	all.map = read_map(fd);

	parse_player(&all);
	parse_sprite (&all);
	parse_resolution (&all);
	parse_path (&all);
	parse_color_floor(&all);
	parse_color_sky(&all);
	tex_open(&all);
	sprites_open (&all);
	get_tex_data(&all);

    img.mlx_win = mlx_new_window(img.mlx, all.w, all.h, "cub");
    img.img = mlx_new_image(img.mlx, all.w, all.h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);






    //what to draw - start

	sky_floor(&all);
    drawscreen(&all);
    // what to draw - end
    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
    mlx_loop(img.mlx);
}