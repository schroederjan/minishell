
#include "../../includes/minishell.h"

t_tokens	identify_token(const char *str, int pos) 
{
	if (str[pos] == '|')
		return PIPE_MAP;
	else if (str[pos] == '>') 
	{
		if (str[pos + 1] == '>')
			return DOUBLE_GREAT;
		return GREAT_MAP;
	}
	else if (str[pos] == '<')
	{
		if (str[pos + 1] == '<')
			return DOUBLE_LESS;
		return LESS_MAP;
	}
	return NO_TOKEN;
}

int		add_lexer_node(char *tval, t_tokens ttype, t_lexer **head) 
{
	t_lexer *new;

	if (!head)
		return 0;
	new = ft_lexer_new_node(tval, ttype);
	if (!new)
		return 0;
	ft_lexer_add_node_back(head, new);
	return 1;
}
