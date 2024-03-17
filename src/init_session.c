#include "../includes/minishell.h"

int	init_session(t_session *session)
{
	session->commands = NULL;
	session->lexer_list = NULL;
	session->reset_program = false;
	session->pid = NULL;
	session->heredoc = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	init_session_path(session);
	init_session_signals();
	printf("INIT SESSION\n");
	return (1);
}

int init_session_pwd(t_session *session) 
{
	int i;
	size_t len;
	int found;

	i = 0;
	found = 0;
	while (session->env[i] && found < 2) 
	{
		len = ft_strlen(session->env[i]);
		if (!ft_strncmp(session->env[i], "PWD=", 4))
		{
			session->pwd = ft_substr(session->env[i], 4, len - 4);
			found++;
		}
		else if (!ft_strncmp(session->env[i], "OLDPWD=", 7))
		{
			session->old_pwd = ft_substr(session->env[i], 7, len - 7);
			found++;
		}
		i++;
	}
	if (found > 0)
		return (1);
	else
		return (0);
}
