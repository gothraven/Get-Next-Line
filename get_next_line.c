/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 01:39:49 by szaghban          #+#    #+#             */
/*   Updated: 2018/08/25 01:40:42 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** \brief	Function for retreving a specific node.
**
** \details The function looks  for  the node using
** 			the key integer  fd and returns it, but
**			if it is not found,  it  creats  a  new
**			node with  the  same  key  and  returns
**			it as well.
**
** \return 	static t_gnl node
*/

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

/*
** \brief	Function for storing and/or looking for
**			the string which ends with a new line.
**
** \details	The function reads BUFF_SIZE characters
**			from the file  refrenced  with  the  fd
**			inside the  t_gnl  object  passed in as
**			an argument, repeatedly until  it finds
**			the next new line charachter "\n", then
**			it returns the hole line and store  the
**			rest of charachters read from the file.
**
** \return 	static string
*/

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
	SWAP_FREE(tmp, curr->buffer,
		ft_strsub(buffer, NL_INDEX + 1, BUFF_SIZE - NL_INDEX));
	return (str);
}

/*
** \brief 	Function for reading muiltiple files's
**			lines line by line.
**
** \details	The function reads & returns  the next
**			line from a file refrenced  with   its
**			file   descriptor,    everytime    the
**			function is called. It  can  be called
**			with  diffrent  file  descriptors,  it
**			will alwats returns the next line.
**
** \note	The function never opens or closes the
**			file descriptor  passed  in,  it  also
**			fails if the second argument is NULL.
**
** \return 	-1 in case of an ERROR
**			 1 in case of SUCCESS
**			 0 for the end of file
*/

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*curr;
	char			buffer[BUFF_SIZE + 1];
	size_t			size;

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL || BUFF_SIZE < 1)
		return (EXIT_ERROR);
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
	return (1);
}
