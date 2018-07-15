/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:51:58 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 21:55:13 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	sign = 0;
	i = 0;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\r')
			|| (str[i] == '\t') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += ((int)str[i] - '0');
		i++;
	}
	if (sign)
		return (-result);
	else
		return (result);
}
