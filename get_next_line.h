/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <szaghban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:34:46 by szaghban          #+#    #+#             */
/*   Updated: 2018/07/22 22:28:31 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define EXIT_ERROR -1
# define EXIT_SUCCUESS 1
# define EXIT_END 0
# define BUFF_SIZE 42
# define FD_MAX_NUMBER 10
# define SECURE(x) if (!x) return(0x0);
# define HANDEL_ERROR(x, y, z, k) if (x < 0 || y == -1 || z == NULL || k < 1) return (EXIT_ERROR)
# define SWAP_FREE(x, y, z) x = y; y = z; free(x);
# define NL_INDEX (nlc - buffer)

# define IS_ERROR(x) if (x == EXIT_ERROR) return(EXIT_ERROR)
# define IS_END(x) if (x == EXIT_END) return(EXIT_END)
# define CHECK(x) if (!x) return(EXIT_ERROR);


typedef struct		s_gnl
{
    int             fd;
 	char			*buffer;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
