
#include "../includes/minishell.h"

void	print_parser(t_simple_cmds simple_cmds);

/*
The code is a function `initialize_cmd` that takes a `t_parser_tools` struct
pointer as a parameter and returns a pointer to a `t_simple_cmds` struct.

1. It first removes any redirections from the `parser_tools` using the
`rm_redirections` function.
2. It counts the number of arguments in the `lexer_list` of the `parser_tools`
using the `count_args` function.
3. It allocates memory for an array of strings `str` to store the arguments,
with a size of `arg_size + 1`.
4. If the memory allocation fails, it calls `parser_error` function with an
error code of 1.
5. It then iterates through the `lexer_list` and copies each argument string
into the `str` array using `ft_strdup`.
6. It deletes each node from the `lexer_list` as it copies the argument.
7. Finally, it creates a new `t_simple_cmds` struct using the
`ft_simple_cmdsnew` function with the `str` array, number of redirections, and
redirections from the `parser_tools`, and returns a pointer to this new struct.

In summary, the code initializes a command structure by extracting arguments
from the lexer list in the parser tools and creating a new simple command
structure with these arguments and redirection information.
*/
t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	tmp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
			tmp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str,
			parser_tools->num_redirections, parser_tools->redirections));
}

/*
The given code is a function `handle_pipe_errors` that takes in a pointer to a
`t_tools` struct and a `t_tokens` enum variable `token`.

1. The function first checks if the `token` is equal to `PIPE`. If it is, it
calls the function `parser_double_token_error` with parameters `tools`,
`tools->lexer_list`, and `tools->lexer_list->token`, and then returns
`EXIT_FAILURE`.

2. Next, it checks if the `tools->lexer_list` is NULL. If it is, it calls the
function `parser_error` with parameters `0`, `tools`, and `tools->lexer_list`,
and then returns `EXIT_FAILURE`.

3. If none of the above conditions are met, the function simply returns
`EXIT_SUCCESS`.

In summary, this function is used to handle errors related to the presence of a
pipe token or a NULL `lexer_list` in the `tools` struct.
*/
int	handle_pipe_errors(t_tools *tools, t_tokens token)
{
	if (token == PIPE)
	{
		parser_double_token_error(tools, tools->lexer_list,
			tools->lexer_list->token);
		return (EXIT_FAILURE);
	}
	if (!tools->lexer_list)
	{
		parser_error(0, tools, tools->lexer_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
The code defines a function `parser` that takes a pointer to a structure
`t_tools` as a parameter. Within the function:
1. It initializes a pointer `node` of type `t_simple_cmds` and a variable
`parser_tools` of type `t_parser_tools`.
2. Sets `tools->simple_cmds` to NULL.
3. Calls the function `count_pipes` passing `tools->lexer_list` and `tools` as
arguments.
4. Checks if the token of `tools->lexer_list` is PIPE, and if so, calls
`parser_double_token_error` function and returns the result.
5. Enters a while loop that iterates as long as `tools->lexer_list` is not NULL.
6. Within the loop, it checks if `tools->lexer_list` is not NULL and if the
token is PIPE, it deletes the node using `ft_lexerdelone` function.
7. Calls `handle_pipe_errors` function passing `tools` and the token of
`tools->lexer_list` as arguments. If an error is detected, it returns
`EXIT_FAILURE`.
8. Initializes `parser_tools` using `init_parser_tools` function with
`tools->lexer_list` and `tools` as arguments.
9. Initializes `node` by calling `initialize_cmd` function passing
`parser_tools` as an argument.
10. If `node` is NULL, it calls `parser_error` function with appropriate
arguments.
11. If `tools->simple_cmds` is NULL, it assigns `node` to `tools->simple_cmds`,
otherwise it adds `node` to the end of the list using `ft_simple_cmdsadd_back`
function.
12. Updates `tools->lexer_list` to `parser_tools.lexer_list`.
13. Finally, it returns `EXIT_SUCCESS`.

In summary, the `parser` function parses the input tokens, handles pipe errors,
and constructs a linked list of simple commands to be executed.
*/
int	parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	count_pipes(tools->lexer_list, tools);
	if (tools->lexer_list->token == PIPE)
		return (parser_double_token_error(tools, tools->lexer_list,
				tools->lexer_list->token));
	while (tools->lexer_list)
	{
		if (tools->lexer_list && tools->lexer_list->token == PIPE)
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
		if (handle_pipe_errors(tools, tools->lexer_list->token))
			return (EXIT_FAILURE);
		parser_tools = init_parser_tools(tools->lexer_list, tools);
		node = initialize_cmd(&parser_tools);
		if (!node)
			parser_error(0, tools, parser_tools.lexer_list);
		if (!tools->simple_cmds)
			tools->simple_cmds = node;
		else
			ft_simple_cmdsadd_back(&tools->simple_cmds, node);
		tools->lexer_list = parser_tools.lexer_list;
	}
	return (EXIT_SUCCESS);
}
