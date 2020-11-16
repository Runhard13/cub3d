/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:29 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/16 21:43:00 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	spr_sort(t_all *all)
{
	int			i;
	int			j;
	t_sprs	tmp;

	j = 0;
	while (j < all->item->sprite_count - 1)
	{
		i = 0;
		while (i < all->item->sprite_count - j - 1)
		{
			if (all->ss[i].dist < all->ss[i + 1].dist)
			{
				tmp = all->ss[i];
				all->ss[i] = all->ss[i + 1];
				all->ss[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
