
#include "../../includes/minishell.h"

typedef struct {
    char symbol;
    t_token_map token;
} TokenMap;

static TokenMap tokenMap[] = {
    {'|', PIPE_MAP},
    {'>', GREAT_MAP},
    {'<', LESS_MAP},
};

#define TOKEN_MAP_SIZE (sizeof(tokenMap) / sizeof(tokenMap[0]))

t_token_map identify_token(char symbol)
{
	int		i;

	i = 0;
	while (i < TOKEN_MAP_SIZE) 
	{
		if (tokenMap[i].symbol == symbol)
			return tokenMap[i].token;
		i++;
	}
	return NO_TOKEN;
}

int		add_lexer_node(char *tokenValue, t_tokens type, t_lexer **head) 
{
	t_lexer *new;

	if (!head)
		return 0;
	new = ft_lexer_new_node(tokenValue, type);
	if (!new)
		return 0;
	ft_lexer_add_node_back(head, new);
	return 1;
}

int		process_and_add_token(char *str, int pos, t_lexer **lexer_list)
{
	t_token_map token;
	int advance;

	token = identify_token(str[pos]);
	advance = 1;
	if (token == GREAT && str[pos + 1] == '>') 
	{
		if (!add_lexer_node(NULL, GREAT_GREAT, lexer_list)) 
			return -1;
		advance = 2; // Advance two characters for '>>'
	} 
	else if (token == LESS && str[pos + 1] == '<') 
	{
		if (!add_lexer_node(NULL, LESS_LESS, lexer_list)) 
			return -1;
		advance = 2; // Advance two characters for '<<'
	}
	else if (token != NO_TOKEN)
	{
		if (!add_lexer_node(NULL, token, lexer_list)) 
			return -1;
		else
			return 0;
	}
	return advance; // Return how much we should advance in the input string
}
