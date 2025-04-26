# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprigent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by aprigent          #+#    #+#              #
#    Updated: 2025/02/02 22:39:13 by aprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = rush-02

SRCS = srcs/checker.c \
	   srcs/rm_space.c \
	   srcs/dict.c \
	   srcs/nbr.c \
	   srcs/ft_split.c \
	   srcs/fct.c \
	   srcs/algo.c \
	   srcs/write.c \
	   srcs/main.c 

OBJS = ${SRCS:.c=.o}

CC = cc -ggdb

CFLAGS = -Wall -Werror -Wextra

INCLUDES = includes/

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: clean all
