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
