/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:52:27 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/13 12:13:23 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-214748364", 10);
		n = 8;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}
