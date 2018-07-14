/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:48:46 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:48:48 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str2len(char **str)
{
	int		res;
	int		i;

	i = -1;
	res = 0;
	while (str[++i] != 0x0)
		res += ft_strlen(str[i]);
	return (res);
}

char		*ft_strmerge(char **str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = -1;
	if (!str || !*str)
		return (0x0);
	len = ft_str2len(str);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0x0);
	i = -1;
	len = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			res[len] = str[i][j];
			len++;
		}
	}
	res[len] = '\0';
	return (res);
}
