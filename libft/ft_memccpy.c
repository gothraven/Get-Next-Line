/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:11:23 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 18:16:54 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	if (n)
	{
		d = (unsigned char *)dst;
		s = (const unsigned char *)src;
		n++;
		while (--n)
		{
			if ((*d++ = *s++) == (unsigned char)c)
				return (d);
		}
	}
	return (0x0);
}
