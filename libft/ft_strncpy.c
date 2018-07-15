/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:55:50 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 19:29:33 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (len != 0)
	{
		len++;
		while (--len != 0)
		{
			if ((*d++ = *s++) == 0)
			{
				while (--len != 0)
					*d++ = 0;
				break ;
			}
		}
	}
	return (dst);
}
