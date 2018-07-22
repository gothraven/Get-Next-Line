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


t_gnl	*ft_fetch_or_create(t_gnl	*list, int	fd)
{
	t_gnl	*node = list;

	if (node == NULL) {
		SECURE((list = (t_gnl*)malloc(sizeof(t_gnl))));
		list->fd = fd;
		list->bindex = 0;
		return (list);
	}
	while (node != NULL && node->fd != fd) {
		if (node->next == NULL) {
			SECURE((node->next = (t_gnl*)malloc(sizeof(t_gnl))));
			node->next->fd = fd;
			list->bindex = 0;
			return (node->next);
		}
		node = node->next;
	}
	if (node != NULL && node->fd == fd)
		return node;
	return (NULL);
}


int	get_next_line(const int	fd, char	**line)
{
	static t_gnl	*list = NULL;
	t_gnl			*curr;
	int				ret;

	HANDEL_ERROR(fd, read(fd, NULL, 0), line);
	CHECK((curr = ft_fetch_or_create(list, fd)));
	while ((ret = read(fd, curr->buffer, BUFF_SIZE)) >= 0) {
		SECURE((*line = (char*)malloc(BUFF_SIZE * sizeof(char))));
		ft_strcpy(*line, curr->buffer);
		curr->bindex += ret;
		ft_strchr(curr->buffer, '\n');
		
		printf("%d\n", curr->bindex);
		printf("%s\n", curr->buffer);
		printf("%s\n", *line);
	}
	IS_END(ret);
	IS_ERROR(ret);
	return (EXIT_SUCCUESS);
}
