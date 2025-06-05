# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprigent <aprigent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 21:07:51 by aprigent          #+#    #+#              #
#    Updated: 2025/05/29 21:09:05 by aprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memcpy.c ft_strchr.c \
	   ft_strnstr.c ft_toupper.c ft_isprint.c ft_strlen.c ft_strrchr.c ft_strtrim.c \
	   ft_isascii.c ft_bzero.c ft_memchr.c ft_memset.c ft_strncmp.c ft_tolower.c \
	   ft_memmove.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_split.c \
	   ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c \
	   ft_putendl_fd.c ft_striteri.c ft_putnbr_fd.c ft_strjoin.c ft_strlcpy.c \
	   ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	   ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c \
	   ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	   ft_printf.c parse_flags.c params_handler.c print_char.c print_str.c \
	   print_pointer.c print_int.c print_unsigned.c print_hex.c utils.c \
	   parse_utils.c ft_itoa_unsigned.c \
	   get_next_line.c get_next_line_utils.c

SRCS_DIR = ./srcs/

OBJS = $(SRCS:%.c=${OBJS_DIR}%.o)

OBJS_DIR = ./.objs/

HEADER = ./includes/libft.h ./includes/get_next_line.h ./includes/ft_printf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

${OBJS_DIR}%.o: ${SRCS_DIR}%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJS_DIR}
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
