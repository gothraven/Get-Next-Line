/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:16:48 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 01:40:43 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbdegits(int n, int neg)
{
	long	nb;
	int		i;

	nb = (long)n * neg;
	i = 1;
	while ((nb / 10) > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (neg == -1 ? i + 1 : i);
}

static void		ft_cpdegits(char *tab, int n, int neg)
{
	long nb;

	nb = (long)n * neg;
	*tab++ = (nb % 10) + '0';
	while ((nb / 10) > 0)
	{
		nb = nb / 10;
		*tab++ = (nb % 10) + '0';
	}
	if (neg == -1)
		*tab++ = '-';
}

static void		ft_strrev(char *tab)
{
	char	tmp[ft_strlen(tab)];
	int		i;

	i = -1;
	while (tab[++i])
		tmp[i] = tab[i];
	while (--i >= 0)
		*tab++ = tmp[i];
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		neg;

	neg = (n >= 0 ? 1 : -1);
	if (!(tmp = ft_strnew(ft_nbdegits(n, neg))))
		return (NULL);
	ft_cpdegits(tmp, n, neg);
	ft_strrev(tmp);
	return (tmp);
}
