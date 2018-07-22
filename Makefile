CC = gcc

INCS = get_next_line.h

LIBS = libft/libft.a

DISABLED_WARNINGS = -Wno-implicit-fallthrough

CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wshadow -Wdeclaration-after-statement -Wunused-function ${DISABLED_WARNINGS} -fprofile-arcs -ftest-coverage

LDFLAGS = -fprofile-arcs ${LIBS}

EXEC = gnl

SRC = get_next_line.c main.c 

OBJ = ${SRC:.c=.o}

.PHONY: default clean test

default: ${EXEC}

get_next_line.o: get_next_line.c get_next_line.h
main.o: main.c get_next_line.h

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< 

${EXEC}: ${OBJ}
	@${CC} -o $@ $^ ${LDFLAGS}

clean:
	@rm -f get_next_line.o
	@find . -iname '*.gcda' -delete
	@find . -iname '*.gcov' -delete
	@find . -iname '*.gcno' -delete
	@rm -f ${EXEC}

test:
	@./${EXEC}