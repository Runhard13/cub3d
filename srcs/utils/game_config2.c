/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:29:23 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 19:59:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		init_params(t_all *all)
{
	struct_init(all);
	struct_init2(all);
	parse_all_data(all);
	validate_map(all);
	create_buffers(all);
	parse_sprite(all);
	return (0);
}

void	draw_all(t_all *all)
{
	sky_floor(all);
	drawscreen(all);
}
