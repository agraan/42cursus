# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprigent <marvin42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 17:05:35 by aprigent          #+#    #+#              #
#    Updated: 2025/05/03 11:07:05 by aprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memcpy.c ft_strchr.c \
	   ft_strnstr.c ft_toupper.c ft_isprint.c ft_strlen.c ft_strrchr.c ft_strtrim.c \
	   ft_isascii.c ft_bzero.c ft_memchr.c ft_memset.c ft_strncmp.c ft_tolower.c \
	   ft_memmove.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_split.c \
	   ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c \
	   ft_putendl_fd.c ft_striteri.c ft_putnbr_fd.c ft_strjoin.c ft_strlcpy.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJS_BONUS = $(BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(OBJS_BONUS)

re: fclean all 
