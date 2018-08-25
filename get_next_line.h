/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 01:40:53 by szaghban          #+#    #+#             */
/*   Updated: 2018/08/25 01:40:56 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "libft/libft.h"

# define EXIT_ERROR -1
# define EXIT_END 0
# define BUFF_SIZE 42
# define SECURE(x) if (!x) return(0x0);
# define SWAP_FREE(x, y, z) x = y; y = z; free(x);
# define NL_INDEX (nlc - buffer)

typedef struct		s_gnl
{
	int				fd;
	char			*buffer;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
