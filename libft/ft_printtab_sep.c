/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_sep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:46:01 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:46:08 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printtab_sep(int *tab, int s, char c)
{
	int		i;

	if (!tab || s < 1)
		return (-1);
	i = -1;
	while (++i < s)
	{
		ft_putnbr_fd(tab[i], STDOUT);
		ft_putchar_fd(c, STDOUT);
	}
	ft_putchar_fd('\n', STDOUT);
	return (1);
}
