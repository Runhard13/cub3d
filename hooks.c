/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 17:37:56 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"




int	key_press(int keycode, t_all *all)
{
	mlx_clear_window(all->img->mlx, all->img->mlx_win);

	if (keycode == W || keycode == UP)
		move_forward(all);
	if (keycode == S || keycode == DOWN)
		move_back(all);
	if (keycode == E || keycode == RIGHT)
		rot_left(all);
	if (keycode == Q || keycode == LEFT)
		rot_right(all);
	if (keycode == A )
		strafe_left(all);
	if (keycode == D )
		strafe_right(all);
	if (keycode == ESC)
		exit(0);

	sky_floor(all);
	drawscreen(all);
	return (0);
}
