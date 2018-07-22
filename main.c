/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <szaghban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 20:00:49 by szaghban          #+#    #+#             */
/*   Updated: 2018/07/22 22:36:02 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
    int		fd;
    char	*line;
    int		ret;

    if (argc == 1)
        fd = 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (EXIT_ERROR);
    while ((ret = get_next_line(fd, &line)) == EXIT_SUCCUESS)
    {
        ft_putstr(line);
        free(*line);
    }
    if (argc == 2)
        close(fd);
    return (ret);
}