NAME = minishell

# VARS
# ####

MKDIR = mkdir
CC = gcc
CFLAGS	= -Wall -Werror -Wextra

PATHS = src/
PATH_LIBFT = libs/libft
PATH_LEXER = src/lexer/
PATH_PARSER = src/parser/
PATH_BUILTINS = src/builtins/
PATH_EXPANDER = src/expander/
PATH_UTILS = src/utils/
PATH_ERRORS = src/errors/
PATH_EXECUTOR = src/executor/

PATH_BUILD = build/
PATH_OBJS = build/objs/
BUILD_PATHS = $(PATH_BUILD) $(PATH_OBJS)

SRCS = $(shell find ./src -iname "*.c")
OBJS = $(addprefix $(PATH_OBJS), $(notdir $(patsubst %.c, %.o, $(SRCS))))

LIBFT = $(PATH_LIBFT)/libft.a
HEADERS = $(shell find ./includes -iname "*.h")

# TODO: Whats that? Why would we need it?
# READLINE_DIR = $(shell brew --prefix readline)
# READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
# INCLUDES = -Iincludes -I$(PATH_LIBFT) -I$(READLINE_DIR)/include

INCLUDES = -Iincludes -I$(PATH_LIBFT)

# COMMANDS
# ########

all: $(BUILD_PATHS) $(NAME)

$(PATH_OBJS)%.o:: $(PATHS)%.c
	@echo "Compiling ${notdir $<} in	$(PATHS)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_LEXER)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_LEXER)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_PARSER)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_PARSER)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_BUILTINS)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_BUILTINS)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_EXPANDER)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_EXPANDER)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_UTILS)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_UTILS)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_ERRORS)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_ERRORS)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_EXECUTOR)%.c $(HEADERS)
	@echo "Compiling ${notdir $<} in	$(PATH_EXECUTOR)"
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

	@echo "Success"

$(LIBFT):
	@$(MAKE) -C $(PATH_LIBFT)

$(PATH_BUILD):
	@$(MKDIR) $(PATH_BUILD)

$(PATH_OBJS):
	@$(MKDIR) $(PATH_OBJS)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f $(PATH_BUILD).tmp*
	@rmdir $(PATH_OBJS) $(PATH_BUILD)
	@make fclean -C $(PATH_LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

norm:
	@norminette ./includes
	@norminette ./src
	@norminette ./libs/libft

# CONFIGS
# #######

.PRECIOUS: $(PATH_OBJS)%.o
.PHONY: all clean fclean re norm
