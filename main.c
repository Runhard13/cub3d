/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/10 22:01:34 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void drawscreen(t_all *all)
{
	int x = 0;
	double ZBuffer[w];
	//arrays used to sort the sprites
	int spriteOrder[all->item->sprite_count];
	double spriteDistance[all->item->sprite_count];

	while (x++ < w)
	{
		double cameraX = 2 * x / (double) w - 1; //x-coordinate in camera space
		double rayDirX = all->plr->dirX + all->plr->planeX * cameraX;
		double rayDirY = all->plr->dirY + all->plr->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int) (all->plr->posX);
		int mapY = (int) (all->plr->posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (all->plr->posX - mapX) * deltaDistX;
		} else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - all->plr->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (all->plr->posY - mapY) * deltaDistY;
		} else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - all->plr->posY) * deltaDistY;
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
		if (side == 0) perpWallDist = (mapX - all->plr->posX + (1 - stepX) / 2.0) / rayDirX;
		else perpWallDist = (mapY - all->plr->posY + (1 - stepY) / 2.0) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int) (h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)drawEnd = h - 1;

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = all->plr->posY + perpWallDist * rayDirY;
		else wallX = all->plr->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int) (wallX * (double) (all->north->tex_width));
		if (side == 0 && rayDirX > 0) texX = all->north->tex_width - texX - 1;
		if (side == 1 && rayDirY < 0) texX = all->north->tex_width - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * all->north->tex_height / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - h / 2 + lineHeight / 2) * step;

		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int) texPos & (all->north->tex_height - 1);
			texPos += step;
			int color;
			if (wall_side(side, rayDirX, rayDirY) == texS)
				color = get_color(all->south, texX, texY);
			if (wall_side(side, rayDirX, rayDirY) == texN)
				color = get_color(all->north, texX, texY);
			if (wall_side(side, rayDirX, rayDirY) == texE)
				color = get_color(all->east, texX, texY);
			if (wall_side(side, rayDirX, rayDirY) == texW)
				color = get_color(all->west, texX, texY);
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			//if(side == 1) color = (color >> 1) & 8355711;
			my_mlx_pixel_put(all->img, x, y, color);
		}
		//draw_line(all, side, drawStart, drawEnd, x);
		//SET THE ZBUFFER FOR THE SPRITE CASTING
		ZBuffer[x] = perpWallDist; //perpendicular distance is used
	}
	draw_sprite(all, spriteOrder, spriteDistance, ZBuffer);
	mlx_put_image_to_window(all->img, all->img->mlx_win, all->img->img, 0, 0);
}

void draw_sprite(t_all *all, int *spriteOrder, double *spriteDistance, double *ZBuffer)
{

	//SPRITE CASTING
	//sort sprites from far to close
	for (int i = 0; i < all->item->sprite_count; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((all->plr->posX - all->item[i].x) * (all->plr->posX - all->item[i].x) +
							 (all->plr->posY - all->item[i].x) *
							 (all->plr->posY - all->item[i].x)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, all->item->sprite_count);

	//after sorting the sprites, do the projection and draw them
	for (int i = 0; i < all->item->sprite_count; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = all->item[spriteOrder[i]].x - all->plr->posX;
		double spriteY = all->item[spriteOrder[i]].y - all->plr->posY;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (all->plr->planeX * all->plr->dirY -
							   all->plr->dirX * all->plr->planeY); //required for correct matrix multiplication

		double transformX = invDet * (all->plr->dirY * spriteX - all->plr->dirX * spriteY);
		double transformY = invDet * (-all->plr->planeY * spriteX + all->plr->planeX *
																	spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int) ((w / 2) * (1 + transformX / transformY));

		//calculate height of the sprite on screen
		int spriteHeight = abs(
				(int) (h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + h / 2;
		if (drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + h / 2;
		if (drawEndY >= h) drawEndY = h - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int) (h / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= w) drawEndX = w - 1;

		//loop through every vertical stripe of the sprite on screen
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX =
					(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * all->sprite->tex_width / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
				for (int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
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
    img.mlx_win = mlx_new_window(img.mlx, w, h, "cub");
    img.img = mlx_new_image(img.mlx, w, h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);



    all.plr = &plr;
    all.img = &img;
    all.north = &north;
    all.west = &west;
    all.south = &south;
    all.east = &east;
    all.sprite = &sprite;
    all.item = &item;
    all.map = read_map(fd);

	find_player (&all);
	tex_open(&all);
	sprites_open (&all);
	get_tex_data(&all);


    //what to draw - start

	sky_floor(&all);
    drawscreen(&all);
    // what to draw - end
    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
    mlx_loop(img.mlx);
}