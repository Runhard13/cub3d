/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      :::::::: q  */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:18:57 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 23:13:31 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../another cub/cub3d.h"

void draw_line (t_all *all, double dist, int i)
{
	double h = 1080;
	int pplane = 1920 /2 / tan(0.523599);
	//Calculate height of line to draw on screen
	int H = (SCALE / dist) * pplane;

	//calculate lowest and highest pixel to fill in current stripe
	unsigned int drawStart = (h / 2 - H / 2);
	unsigned int drawEnd = drawStart + H;

	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(all->win, i, drawStart, 0xFFFFFF);
		drawStart++;
	}
}