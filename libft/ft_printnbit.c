/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:29:56 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:33:07 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printnbit(int val, int max)
{
	int		i;
	int		power;
	char	s[32];

	i = 0;
	if (max < 1 || max > 32)
		return (-1);
	power = ft_power2((unsigned int)max - 1);
	while (i < max)
	{
		if (val & power)
			s[i] = '1';
		else
			s[i] = '0';
		i++;
		val = val << 1;
	}
	s[i] = '\n';
	s[i + 1] = '\0';
	write(1, s, max);
	return (1);
}
