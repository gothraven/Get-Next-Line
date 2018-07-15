/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:09:13 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/14 01:29:06 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(tmp = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s[++i])
		tmp[i] = f(s[i]);
	tmp[i] = '\0';
	return (tmp);
}
