NAME = minishell

# VARS
# ####

MKDIR = mkdir
CC = gcc
CFLAGS	= -Wall -Werror -Wextra

PATH_OBJS = build/objs/
PATH_LIBFT = libs/libft

PATHS = src/
PATH_LEXER = $(PATHS)lexer/
PATH_PARSER = $(PATHS)parser/
PATH_BUILTINS = $(PATHS)builtins/
PATH_EXPANDER = $(PATHS)expander/
PATH_UTILS = $(PATHS)utils/
PATH_CLEANUP = $(PATHS)cleanup/
PATH_INIT = $(PATHS)init/
PATH_EXECUTOR = $(PATHS)executor/

VPATH = $(PATHS):\
	$(PATH_LEXER):\
	$(PATH_PARSER):\
	$(PATH_BUILTINS):\
	$(PATH_EXPANDER):\
	$(PATH_UTILS):\
	$(PATH_CLEANUP):\
	$(PATH_INIT):\
	$(PATH_EXECUTOR)

SRCS = $(shell find $(PATHS) -type f -name '*.c')
OBJS = $(SRCS:$(PATHS)%.c=$(PATH_OBJS)%.o)
OBJ_DIRS = $(dir $(OBJS))

LIBFT = $(PATH_LIBFT)/libft.a
HEADERS = $(shell find ./includes -iname "*.h")

READLINE_LIB = -lreadline -lhistory -ltermcap
INCLUDES = -Iincludes -I$(PATH_LIBFT)

# COMMANDS
# ########

all: $(NAME)

$(OBJ_DIRS):
	@$(MKDIR) -p $@

$(PATH_OBJS)%.o: %.c $(HEADERS) | $(OBJ_DIRS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(READLINE_LIB)
	@echo "\n\033[33;1;3mMinishell ready!\033[0m"

$(LIBFT):
	@echo "Making libft..."
	@$(MAKE) -C $(PATH_LIBFT)

clean:
	@echo "Removing .o object files..."
	@rm -rf $(PATH_OBJS)
	@make fclean -C $(PATH_LIBFT)

fclean: clean
	@echo "Removing minishell..."
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette ./src
	@norminette -R CheckForbiddenSourceHeader ./includes

val:
	@valgrind --track-fds=yes ./minishell

# CONFIGS
# #######

.PHONY: all clean fclean re norm
