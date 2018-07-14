/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:51:18 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:51:20 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lennbr_base(long nb, size_t b)
{
	size_t	res;

	res = 0;
	if (b < 1 || b > 16 || nb > ft_power2(31) + 5)
		return (0);
	if (nb == 0)
		return (1);
	if (nb < 0 && b == 10)
	{
		nb *= -1;
		res++;
	}
	while (nb)
	{
		nb = nb / b;
		res++;
	}
	return (res);
}
