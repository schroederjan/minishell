#include "../../includes/minishell.h"

void	reset_lexer(t_lexer **lexer_lst)
{
	t_lexer	*current;
	t_lexer *next_node;

	if (lexer_lst == NULL || *lexer_lst == NULL)
		return ;
	current = *lexer_lst;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->word != NULL)
			free(current->word);
		free(current);
		current = next_node;
	}
	*lexer_lst = NULL;
}

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
