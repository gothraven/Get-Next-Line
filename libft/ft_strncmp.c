/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:49:45 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/13 23:23:07 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	if (!n)
		return ((int)n);
	while (ss1[i] && ss2[i] && ss1[i] == ss2[i] && i < n - 1)
		i++;
	if (!ss1[i] && !ss2[i])
		return (0);
	else
		return ((int)(ss1[i] - ss2[i]));
}
