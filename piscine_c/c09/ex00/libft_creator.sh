#/bin/sh
cc -Werror -Wextra -Wall -I. -g -O -c ft_putchar.c ft_putstr.c ft_strlen.c ft_swap.c ft_strcmp.c
ar rcs libft.a *.o
ranlib libft.a
