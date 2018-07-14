/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:34:57 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 02:10:38 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] && needle[j] && i < len)
	{
		if (needle[j] == haystack[i])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (!needle[j])
		return (&((char *)haystack)[i - j]);
	else
		return (0);
}
