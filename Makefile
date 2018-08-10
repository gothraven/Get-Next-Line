EXEC = gnl
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -I libft/includes
LDFLAGS = -fprofile-arcs -I libft/includes -L libft/ -lft
SRC = get_next_line.c main.c
OBJ = ${SRC:.c=.o}

.PHONY: default clib clean test

default: clib ${EXEC}

get_next_line.o: get_next_line.c get_next_line.h
main.o: main.c get_next_line.h

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< 

${EXEC}: ${OBJ}
	${CC} -o $@ $^ ${LDFLAGS}

clib:
	make -C libft/ fclean && make -C libft/

clean:
	rm -f get_next_line.o
	rm -f main.o
	find . -iname '*.gcda' -delete
	find . -iname '*.gcov' -delete
	find . -iname '*.gcno' -delete
	rm -f ${EXEC}
	make -C libft/ fclean

test:
	./${EXEC} Makefile