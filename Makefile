NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

READLINE_PATH = /usr/include/readline
READLINE_LIB = -lreadline

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c' -exec basename {} \;)
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -I$(READLINE_PATH) $(READLINE_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(READLINE_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
re: fclean all

norm:
	@norminette ./src
	@norminette -R CheckForbiddenSourceHeader ./includes

val:
	@valgrind --track-fds=yes ./minishell

.PHONY: all clean fclean re norm
