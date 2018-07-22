#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft/libft.h"

#define EXIT_ERROR -1
#define EXIT_SUCCUESS 1
#define EXIT_END 0
#define BUFF_SIZE 100
#define FD_MAX_NUMBER 10


// typedef struct 	Gnl_s {
// 	static char buffer[BUFF_SIZE];
// 	char		*tmp;
// 	int			fd;
// }	 			Gnl_t;


int	get_next_line(const int fd, char **line);


#endif
