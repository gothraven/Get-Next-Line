/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:51:17 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/14 01:21:54 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tmp;

	if (!(tmp = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < size)
		tmp[i] = '\0';
	tmp[i] = '\0';
	return (tmp);
}
