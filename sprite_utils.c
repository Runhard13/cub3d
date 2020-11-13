/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:29 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/14 01:02:57 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites_open(t_all *all)
{
	all->sprite->tex_img =
			mlx_xpm_file_to_image(all->img->mlx, all->sprite->path,
					&all->sprite->tex_width, &all->sprite->tex_height);
}

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_dblswap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	spr_sort(int *order, double *distance, int number)
{
	int i;
	int	j;

	i = 0;
	j = 1;
	while (i < number)
	{
		while (j < number)
		{
			if (distance[j] < distance[i])
			{
				ft_swap(&order[i], &order[j]);
				ft_dblswap(&distance[i], &distance[j]);
			}
			j++;
		}
		i++;
		j = i;
	}
}
