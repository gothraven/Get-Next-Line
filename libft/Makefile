# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szaghban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 15:23:16 by szaghban          #+#    #+#              #
#    Updated: 2017/12/22 02:46:32 by szaghban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SNAME := libft.so
INCLUDES := .
FUNS := ft_bzero ft_memcpy ft_memmove ft_memset ft_memccpy ft_memchr \
	ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat \
	ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr \
	ft_strcmp ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	ft_toupper ft_tolower ft_isprint ft_strncmp ft_memalloc ft_memdel \
	ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
	ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
	ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
	ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_lstrev \
	ft_printbit ft_printbit_rev ft_printnbit ft_printnbit_rev\
	ft_power2 ft_itoa_base ft_lennbr_base\
	ft_strcjoin ft_strmerge ft_printtab_sep\
	ft_printbase ft_isupper ft_islower
FLAGS := -Wall -Wextra -Werror
INCF = -I $(INCLUDES)
BINS = $(patsubst %,%.o,$(FUNS))

.PHONY: all clean fclean re so norme

all: $(NAME)

$(BINS):
	@gcc $(INCF) $(FLAGS) -c $(patsubst %.o,%.c,$@)

$(NAME): $(BINS)
	@ar rc $(NAME) $(BINS)

so: fclean $(BINS)
	@gcc -shared -o $(SNAME) *.o

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME) $(SNAME)

re: fclean all

norme: fclean
	@norminette *.h *.c
