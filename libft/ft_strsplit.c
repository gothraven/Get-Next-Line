/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:12:51 by szaghban          #+#    #+#             */
/*   Updated: 2017/12/22 01:41:29 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_letter_counter(char const *s, char c)
{
	int		i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	return (i);
}

static int		ft_word_counter(char const *s, char c)
{
	int		i;
	int		word;

	i = -1;
	word = 0;
	if (s == NULL)
		return (i);
	while (s[++i] && s[i] == c)
		;
	while (s[i])
	{
		word++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		words_nb;
	int		letter_nb;
	int		i;
	int		j;

	words_nb = ft_word_counter(s, c) + 1;
	if (words_nb == -1
			|| !(tmp = (char **)malloc((words_nb) * sizeof(char **))))
		return (NULL);
	i = 0;
	while (--words_nb > 0)
	{
		while (*s && *s == c)
			s++;
		letter_nb = ft_letter_counter(s, c);
		if (!(tmp[i] = ft_strnew(letter_nb + 1)))
			return (NULL);
		j = 0;
		while (*s && *s != c)
			tmp[i][j++] = *s++;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
