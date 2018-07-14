/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:18:43 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 21:24:58 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] && needle[j])
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
