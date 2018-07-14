/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:34:37 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:34:42 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_power2(unsigned int val)
{
	unsigned int res;

	res = 1;
	if (val > 31)
		return (0);
	if (val == 31)
		return (2147483648);
	while (val > 0)
	{
		res *= 2;
		val--;
	}
	return (res);
}
