/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:30:25 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 00:56:14 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_sprite(t_all *all, int *spr_ord, double *spr_dist)
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
			if (transformY > 0 && stripe > 0 && stripe < all->w && transformY < all->zbuffer[stripe])
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