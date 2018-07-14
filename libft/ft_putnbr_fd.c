/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:03:25 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 01:41:54 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_nbr_fd(long nb, int fd)
{
	if (nb / 10 > 0)
		ft_nbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_nbr_fd(ABS((long)n), fd);
}
