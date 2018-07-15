/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:04:30 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/07 23:07:17 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned long	*s;
	unsigned char	*c;

	s = (unsigned long*)b;
	len += 8;
	while ((len -= 8) > 8)
		*s++ = 0;
	c = (unsigned char*)s;
	while (len--)
		*c++ = '\0';
}
