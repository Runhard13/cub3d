/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:30:25 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 12:30:42 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_sprite(t_all *all, int *spr_ord, double *spr_dist)
{

	int i;
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int spriteScreenX;
	int spriteHeight;
	int drawStartY;
	int drawEndY;
	int spriteWidth;
	int drawStartX;
	int drawEndX;
	int y;


	i = 0;
	y = 0;
	while (i < all->item->sprite_count)
	{
		spr_ord[i] = i;
		spr_dist[i] = ((all->plr->posx - all->item[i].x) * (all->plr->posx - all->item[i].x) +
					   (all->plr->posy - all->item[i].x) *
					   (all->plr->posy - all->item[i].x));
		i++;
	}
	spr_sort(spr_ord, spr_dist, all->item->sprite_count);

	i = 0;
	while (i < all->item->sprite_count)
	{
		spriteX = all->item[spr_ord[i]].x - all->plr->posx;
		spriteY = all->item[spr_ord[i]].y - all->plr->posy;
		invDet = 1.0 / (all->plr->planex * all->plr->diry - all->plr->dirx * all->plr->planey);
		transformX = invDet * (all->plr->diry * spriteX - all->plr->dirx * spriteY);
		transformY = invDet * (-all->plr->planey * spriteX + all->plr->planex * spriteY);
		spriteScreenX = (int)((all->w / 2) * (1 + transformX / transformY));
		spriteHeight = abs((int)(all->h / (transformY)));
		drawStartY = -spriteHeight / 2 + all->h / 2;
		if (drawStartY < 0)
			drawStartY = 0;
		drawEndY = spriteHeight / 2 + all->h / 2;
		if (drawEndY >= all->h)
			drawEndY = all->h - 1;
		spriteWidth = abs((int) (all->h / (transformY)));
		drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= all->w)
			drawEndX = all->w - 1;

		while (drawStartX < drawEndX)
		{
			int texX = (256 * (drawStartX - (-spriteWidth / 2 + spriteScreenX)) * all->sprite->tex_width / spriteWidth) / 256;
			if (transformY > 0 && drawStartX > 0 && drawStartX < all->w && transformY < all->zbuffer[drawStartX])
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					int d = (y) * 256 - all->h * 128 + spriteHeight * 128;
					int texY = ((d * all->sprite->tex_height) / spriteHeight) / 256;
					int color = get_color(all->sprite, texX, texY);
					if ((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(all->img, drawStartX, y, color);
					y++;
				}
			}
			drawStartX++;
		}
		i++;
	}
}
