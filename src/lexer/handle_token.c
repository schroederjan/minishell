
#include "../../includes/minishell.h"

// GREAT
static int		handle_great_map(char *str, int pos, t_lexer **lexer_list) 
{
	if (str[pos + 1] == '>') 
	{
		if (!add_lexer_node(NULL, DOUBLE_GREAT, lexer_list)) 
			return -1;
		return 2;
	}
	else 
	{
		if (!add_lexer_node(NULL, GREAT_MAP, lexer_list))
			return -1;
		return 1;
	}
}

// LESS
static int		handle_less_map(char *str, int pos, t_lexer **lexer_list)
{
	if (str[pos + 1] == '<') 
	{
		if (!add_lexer_node(NULL, DOUBLE_LESS, lexer_list)) 
			return -1;
		return 2;
	}
	else 
	{
		if (!add_lexer_node(NULL, LESS_MAP, lexer_list))
			return -1;
		return 1;
	}
}

// PIPE
static int handle_pipe_map(t_lexer **lexer_list) 
{
	if (!add_lexer_node(NULL, PIPE_MAP, lexer_list))
		return -1;
	return 1;
}

// TOKEN
int		handle_token(char *str, int pos, t_lexer **lexer_list, t_tokens ttype) 
{
	if (ttype == GREAT_MAP)
		return handle_great_map(str, pos, lexer_list);
	else if (ttype == LESS_MAP)
		return handle_less_map(str, pos, lexer_list);
	else if (ttype == PIPE_MAP)
		return handle_pipe_map(lexer_list);
	else
		return -1;
}
