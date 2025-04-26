# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by babodere          #+#    #+#              #
#    Updated: 2025/02/05 21:03:06 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = bsq

SRCS = 		 srcs/bsq.c \
			 srcs/file_handler.c \
			 srcs/solve.c \
			 srcs/print.c \
			 srcs/utils.c \
			 srcs/checks.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -ggdb

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
