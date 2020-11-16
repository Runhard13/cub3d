/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:59:55 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/16 21:26:01 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game_config (t_all *all)
{
	parse_player(all);
	parse_sprite_count (all);
	parse_resolution (all);
	parse_path_tex(all);
	parse_path_sprite(all);
	parse_color_floor(all);
	parse_color_sky(all);

	if(!(tex_open(all)))
		return(error(all, "Textures loading error"));
	get_tex_data(all);
	return (1);
}