NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes -L$(LIBFT_DIR) -lft

LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = ./includes/push_swap.h $(LIBFT_DIR)includes/libft.h

LDFLAGS = -L$(LIBFT_DIR) -lft

SRCS_DIR = ./srcs/

SRCS = main.c parse.c

OBJS_DIR = ./.objs/

OBJS = $(SRCS:%.c=${OBJS_DIR}%.o)

$(NAME): $(OBJS) ${INCLUDES} $(LIBFT)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
