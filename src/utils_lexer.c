#include "../includes/minishell.h"

t_lexer	 *ft_lexer_new_node(char *str, int token)
{
	t_lexer		*lexer_node;
	static int	i = 0;

	lexer_node = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer_node)
		return (0);
	lexer_node->word = str;
	lexer_node->token = token;
	lexer_node->i = i++;
	lexer_node->next = NULL;
	lexer_node->prev = NULL;
	return (lexer_node);
}

void ft_lexer_add_node_back(t_lexer **lst, t_lexer *new_node)
{
	t_lexer *tmp;

	if (!lst || !new_node) 
		return ;

	if (*lst == NULL)
		*lst = new_node;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node; 
		new_node->prev = tmp;
	}
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
