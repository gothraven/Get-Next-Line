/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:24:55 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 23:31:34 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if (!(tmp = (unsigned char*)malloc(size * sizeof(unsigned char))))
		return (0x0);
	i = -1;
	while (++i < size)
		tmp[i] = 0;
	return (tmp);
}
