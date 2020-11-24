/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:59:55 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/23 20:18:09 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parse_all_data(t_all *all)
{
	parse_player(all);
	parse_sprite_count(all);
	parse_resolution(all);
	parse_path_tex(all);
	parse_path_sprite(all);
	parse_color_floor(all);
	parse_color_sky(all);
	if (!(tex_open(all)))
		return (error(all, "Textures loading error"));
	get_tex_data(all);
	return (1);
}

int		struct_init(t_all *all)
{
	if (!(all->plr = ft_calloc(1, sizeof(t_plr))))
		return (error(all, "struct_init malloc error"));
	if (!(all->north = ft_calloc(1, sizeof(t_tex))))
		return (error(all, "struct_init malloc error"));
	if (!(all->south = ft_calloc(1, sizeof(t_tex))))
		return (error(all, "struct_init malloc error"));
	if (!(all->west = ft_calloc(1, sizeof(t_tex))))
		return (error(all, "struct_init malloc error"));
	if (!(all->east = ft_calloc(1, sizeof(t_tex))))
		return (error(all, "struct_init malloc error"));
	if (!(all->sprite = ft_calloc(1, sizeof(t_tex))))
		return (error(all, "struct_init malloc error"));
	if (!(all->rgb = ft_calloc(1, sizeof(t_rgb))))
		return (error(all, "struct_init malloc error"));
	return (0);
}

int		struct_init2(t_all *all)
{
	if (!(all->item = ft_calloc(1, sizeof(t_spr))))
		return (error(all, "struct_init2 malloc error"));
	if (!(all->cast = ft_calloc(1, sizeof(t_cast))))
		return (error(all, "struct_init2 malloc error"));
	if (!(all->tex = ft_calloc(1, sizeof(t_texture))))
		return (error(all, "struct_init malloc error"));
	return (0);
}

int		create_buffers(t_all *all)
{
	if (!(all->item->spr_dist =
			malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite_dist array allocation error"));
	if (!(all->item->spr_ord = malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite_ord array allocation error"));
	if (!(all->zbuffer = malloc(sizeof(t_all) * all->w)))
		return (error(all, "ZBuffer allocation error"));
	if (!(all->ss = malloc(sizeof(t_all) * all->item->sprite_count)))
		return (error(all, "Sprite coord array alloc error"));
	ft_memset(all->item->spr_ord, 0, (sizeof(t_all) * all->item->sprite_count));
	ft_memset(all->item->spr_dist, 0,
			(sizeof(t_all) * all->item->sprite_count));
	ft_memset(all->zbuffer, 0,
			sizeof(t_all) * all->w);
	ft_memset(all->ss, 0, sizeof(t_all) * all->item->sprite_count);
	return (1);
}

int		check_args(t_all *all, int argc, char **argv)
{
	if (argc > 3 || argc == 1)
		return (error_wo_all("Wrong number of arguments"));
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 6))
	&& ft_strlen(argv[2]) == 6)
		all->screenshot = 1;
	return (0);
}
