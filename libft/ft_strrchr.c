/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:51:06 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 21:17:48 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ss;

	ss = 0x0;
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char)c)
			ss = &((char *)s)[i];
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (ss == 0x0)
		return (0x0);
	if (*ss == (char)c)
		return (ss);
	return (0x0);
}
