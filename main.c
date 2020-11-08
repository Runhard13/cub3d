/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:49:16 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/08 20:01:50 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void drawscreen(t_all *all)
{
	int x = 0;
	while (x++ < w)
	{
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = all->plr->dirX + all->plr->planeX * cameraX;
		double rayDirY = all->plr->dirY + all->plr->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)(all->plr->posX);
		int mapY = (int)(all->plr->posY);

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
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (all->plr->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - all->plr->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (all->plr->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - all->plr->posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(all->map[mapX][mapY] == '1') hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - all->plr->posX + (1 - stepX) / 2.0) / rayDirX;
		else          perpWallDist = (mapY - all->plr->posY + (1 - stepY) / 2.0) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;

		draw_line(all, side, drawStart, drawEnd, x);
	}
	mlx_put_image_to_window(all->img, all->img->mlx_win, all->img->img, 0, 0);
}

int main()
{

	int fd = open("./maps/map.cub", O_RDONLY);
	t_data  img;
    t_plr plr;
    t_all all;


    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, w, h, "cub");
    img.img = mlx_new_image(img.mlx, w, h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    all.plr = &plr;
    all.img = &img;
    all.map = read_map(fd);
	find_player (&all);
    all.plr->planeY = 0;
    all.plr->planeX = 0.66;
   // all.plr->dirY = 0;
  //  all.plr->dirX = -1;
  //  all.plr->posY = 10;
  //  all.plr->posX = 10;


    //what to draw - start

	drawscreen(&all);
    // what to draw - end
    mlx_hook(img.mlx_win, 2, (1L << 0), &key_press, &all);
    mlx_loop(img.mlx);
}