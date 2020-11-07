/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:56:48 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/07 16:01:21 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rounding (int dist)
{
	if (dist % 2 == 1)
		return (dist + 1);
	if (dist % 2 == 0)
		rounding (dist / 2);
	if (dist == 0)
		return (dist);

	return 0;
}