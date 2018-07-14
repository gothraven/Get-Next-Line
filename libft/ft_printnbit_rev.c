/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbit_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:30:08 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:30:12 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printnbit_rev(int val, int max)
{
	int		i;
	char	s[32];

	i = 0;
	if (max < 1 || max > 32)
		return (-1);
	while (i < max)
	{
		if (val & 1)
			s[i] = '1';
		else
			s[i] = '0';
		i++;
		val = val >> 1;
	}
	s[i] = '\0';
	write(1, s, max);
	return (1);
}
