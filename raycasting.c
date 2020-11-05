/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:57:35 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/05 21:16:26 by cdrennan         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void raycaster (t_all *all)
 {
	 t_plr plr = *all->plr;

	 plr.fov = 60;
	 plr.left_ray = plr.pov - plr.fov / 2;
	 plr.right_ray = plr.pov + plr.fov / 2;

	 while (plr.left_ray < plr.right_ray)
	 {
	 	while (map?)
		{

		}
		plr.left_ray += plr.fov / 1920;
	 }
 }