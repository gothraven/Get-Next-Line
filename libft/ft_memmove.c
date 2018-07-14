/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:53:41 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 18:18:22 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s;
	unsigned char		*d;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (len == 0)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (--len)
		d[len] = s[len];
	d[0] = s[0];
	return (dst);
}
