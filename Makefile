CC = gcc
CFLAGS = -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -I libft/includes
LDFLAGS = -fprofile-arcs -I libft/includes -L libft/ -lft
SRC = get_next_line.c
OBJ = ${SRC:.c=.o}

.PHONY: default clib clean test re

default: ${OBJ}

get_next_line.o: get_next_line.c get_next_line.h

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< 

clib:
	@make -C libft/ fclean && make -C libft/

clean:
	@rm -f get_next_line.o
	@find . -iname '*.gcda' -delete
	@find . -iname '*.gcov' -delete
	@find . -iname '*.gcno' -delete
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean

re: clean default
