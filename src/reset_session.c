#include "../includes/minishell.h"

void	reset_commands(t_commands **commands_lst)
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
		free(current->str); // Frees the array of strings itself
		current->str = NULL;
		if (current->heredocs_file_name != NULL)
			free(current->heredocs_file_name);
		free(current);
		current = next_node;
	}
	*commands_lst = NULL;
}

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



int		reset_session(t_session *session)
{
	printf("inside reset_session\n");
	reset_commands(&session->commands);
	free(session->arg);
	if (session->pid)
		free(session->pid);
	session->paths = NULL;
	init_session(session);
	session->reset_program = true;
	minishell(session);
	return (1);
}
