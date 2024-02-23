#include "../../includes/minishell.h"

void reset_commands(t_commands **commands_lst)
{
	t_commands	*current;
	t_commands	*next_node;

	if (commands_lst == NULL || *commands_lst == NULL)
		return ;
	current = *commands_lst;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->redirections != NULL)
			reset_lexer(&(current->redirections));
		if (current->str != NULL)
			free_arr(current->str);
		if (current->heredocs_file_name != NULL)
			free(current->heredocs_file_name);
		free(current);
		current = next_node;
	}
	*commands_lst = NULL;
}
