NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR) ./includes/push_swap.h

LDFLAGS = -L$(LIBFT_DIR) -lft

SRCS_DIR = ./srcs

SRCS = push_swap.c 

OBJS_DIR = ./.objs

OBJS = $(SRCS:${SRCS_DIR}%.c=${OBJS_DIR}%.o)

$(NAME): $(OBJS) ${INCLUDES} $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
