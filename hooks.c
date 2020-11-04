/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:44:53 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/04 20:17:33 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int             key_press(int keycode, t_all *all)
{

	mlx_clear_window(all->win->mlx, all->win->mlx_win);
	if (keycode == 13)
		all->plr->y -= 1;
	if (keycode == 1)
		all->plr->y += 1;
	if (keycode == 0)
		all->plr->x -= 1;
	if (keycode == 2)
		all->plr->x += 1;
	if (keycode == 53)
		exit(0);
	redraw_map(all);

	return (0);
}

