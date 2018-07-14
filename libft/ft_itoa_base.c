/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:37:21 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:39:34 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_remp_tab(char *str)
{
	int i;

	i = -1;
	while (++i < 10)
		str[i] = i + '0';
	i = -1;
	while (++i < 6)
		str[10 + i] = i + 'A';
	str[16] = '\0';
}

static void		ft_remp_res(char *res, char *str, long nb, int b)
{
	if (nb > 0)
	{
		res[0] = str[nb % b];
		ft_remp_res(&res[1], str, nb / b, b);
	}
}

static int		ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp[1024];

	if (!str || (i = ft_strlen(str)) > 1024)
		return (-1);
	j = i - 1;
	while (--i > -1)
		tmp[i] = str[j - i];
	i = -1;
	while (++i < j + 1)
		str[i] = tmp[i];
	str[i] = '\0';
	return (1);
}

char			*ft_itoa_base(int nb, int base)
{
	long	n;
	size_t	len;
	char	*res;
	char	*tab;

	n = nb;
	if (base == 10 || nb == 0)
		return (ft_itoa(nb));
	if (base < 2 || base > 16)
		return (0);
	if (n < 0)
		n *= -1;
	len = ft_lennbr_base(n, (size_t)base);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0x0);
	if (!(tab = (char *)malloc(sizeof(char) * (17))))
		return (0x0);
	ft_remp_tab(tab);
	res[len] = '\0';
	ft_remp_res(res, tab, n, base);
	ft_strrev(res);
	return (res);
}
