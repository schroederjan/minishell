
#include "../includes/minishell.h"

t_tokens	token_identify(const char *str, int pos) 
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
