
#include "../includes/minishell.h"

/*
The given code defines a function `join_heredoc` that takes two strings `str1`
and `str2` as input and concatenates them together with a space in between.

1. It first checks if `str2` is NULL. If it is, the function returns a duplicate
of `str1` using the `ft_strdup` function.

2. If `str2` is not NULL, it concatenates `str1` and a space using the
`ft_strjoin` function and stores the result in `tmp`.

3. Then, it concatenates `tmp` and `str2` using the `ft_strjoin` function and
stores the final result in `ret`.

4. It then frees the memory allocated for `tmp` and `str2` using the `free`
function.

5. Finally, it returns the concatenated string `ret`.

Overall, the function takes two strings, concatenates them with a space in
between, and returns the resulting string.
*/
// TODO is it even used???
char	*join_heredoc(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;

	if (!str2)
		return (ft_strdup(str1));
	tmp = ft_strjoin(str1, " ");
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	free(str2);
	return (ret);
}

int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = ft_lexernew(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	ft_lexeradd_back(&parser_tools->redirections, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	ft_lexerdelone(&parser_tools->lexer_list, index_1);
	ft_lexerdelone(&parser_tools->lexer_list, index_2);
	parser_tools->num_redirections++;
	return (0);
}

/*
This code defines a function `rm_redirections` that removes redirections from a
list of tokens in a parser.

1. It takes a `t_parser_tools` struct as a parameter.
2. It initializes a `t_lexer` pointer `tmp` to point to the beginning of the
lexer list in the `parser_tools`.
3. It then iterates through the lexer list until it finds a token that is not 0
(indicating a redirection).
4. If the token is a PIPE, the function returns without doing anything.
5. If there is no token after the current one or if the next token is not a
redirection token, it calls `parser_error` function.
6. If the next token is a redirection token, it calls
`parser_double_token_error` function.
7. If the current token is a redirection token (GREAT, LESS, etc.), it calls
`add_new_redirection` function to add this redirection to the parser.
8. Finally, it recursively calls `rm_redirections` function to continue removing
redirections from the lexer list.

Overall, this function is responsible for removing redirection tokens from the
lexer list in the parser_tools struct.
*/
void	rm_redirections(t_parser_tools *parser_tools)
{
	t_lexer	*tmp;

	tmp = parser_tools->lexer_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		parser_error(0, parser_tools->tools, parser_tools->lexer_list);
	if (tmp->next->token)
		parser_double_token_error(parser_tools->tools,
			parser_tools->lexer_list, tmp->next->token);
	// true if in between enum range of redirections
	if ((tmp->token >= GREAT
			&& tmp->token <= LESS_LESS))
		add_new_redirection(tmp, parser_tools);
	rm_redirections(parser_tools);
}
