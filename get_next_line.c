/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <szaghban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:50:16 by szaghban          #+#    #+#             */
/*   Updated: 2018/07/22 23:15:17 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static t_gnl	*ft_fetch_or_create(t_gnl **list, const int fd)
{
	t_gnl	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	SECURE((node = (t_gnl *)malloc(sizeof(t_gnl))));
	node->fd = fd;
	node->buffer = NULL;
	node->next = *list;
	*list = node;
	return (node);
}


static char		*find_and_store(t_gnl *curr, char buffer[BUFF_SIZE + 1])
{
	char	*tmp;
	char	*sub;
	char	*nlc;
	char	*str;
	size_t	size;

	str = ft_strnew(0);
	while (!(nlc = ft_strchr(buffer, '\n')))
	{
		SWAP_FREE(tmp, str, ft_strjoin(str, buffer));
		if (!(size = read(curr->fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(curr->buffer));
			return (str);
		}
		buffer[size] = '\0';
	}
	sub = ft_strsub(buffer, 0, NL_INDEX);
	SWAP_FREE(tmp, str, ft_strjoin(str, sub));
	free(sub);
	SWAP_FREE(tmp, curr->buffer, ft_strsub(buffer, NL_INDEX + 1, BUFF_SIZE - NL_INDEX));
	return (str);
}


int	get_next_line(const int	fd, char	**line)
{
	static t_gnl	*list = NULL;
	t_gnl			*curr;
	char			buffer[BUFF_SIZE + 1];
	size_t			size;

	HANDEL_ERROR(fd, read(fd, NULL, 0), line, BUFF_SIZE);
	curr = ft_fetch_or_create(&list, fd);
	if (curr->buffer && ft_strlen(curr->buffer))
		ft_strcpy(buffer, curr->buffer);
	else
	{
		if (!(size = read(fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(curr->buffer));
			return (EXIT_END);
		}
		buffer[size] = '\0';
	}
	*line = find_and_store(curr, buffer);
	return (EXIT_SUCCUESS);
}
