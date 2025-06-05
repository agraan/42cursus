# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 23:07:05 by aprigent          #+#    #+#              #
#    Updated: 2025/05/20 15:24:22 by aprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = ./srcs/

SRCS = ft_printf.c parse_flags.c params_handler.c utils.c parse_utils.c \
	   print_char.c print_str.c print_pointer.c print_int.c print_unsigned.c \
	   ft_itoa_unsigned.c print_hex.c

OBJS_DIR = ./.objs/

LIBFT = libft

OBJS = ${SRCS:%.c=$(OBJS_DIR)%.o}

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

all: ${NAME}

${NAME}: ${OBJS}
	@make -C $(LIBFT)
	@cp ${LIBFT}/libft.a $(NAME)
	@ar rcs ${NAME} ${OBJS}

$(OBJS_DIR)%.o: ${SRCS_DIR}%.c ${HEADER}
	@mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} -c $< -o $@ 

bonus: all

clean:
	@rm -rf ${OBJS_DIR}
	@make clean -C ${LIBFT}

fclean: clean
	@rm -f ${NAME}
	@make fclean -C ${LIBFT}

re: fclean all 
