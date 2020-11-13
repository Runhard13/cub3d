/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:31:04 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/11 19:39:55 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	//очистка всего
}

/*
void	exit_free(t_params *tmp, int quit)
{
	destroy_images(tmp);
	if (tmp->parser & PARSER_MAP)
		free_tab(tmp->map.tab, tmp->map.size.y);
	if (tmp->parser & PARSER_SPR)
	{
		free(tmp->map.s_order);
		free(tmp->map.s_dist);
		free(tmp->map.sprite);
	}
	if (tmp->parser & PARSER_BUF)
	{
		free(tmp->spritebuffer);
		free(tmp->zbuffer);
	}
	if (tmp->parser & PARSER_DOOR)
	{
		free(tmp->map.d_offset);
		free(tmp->map.d_state);
	}
	if (BONUS)
		destroy_bonus_images(tmp);
	free(tmp->vars.mlx);
	if (quit)
		exit(EXIT_FAILURE);
}
*/
