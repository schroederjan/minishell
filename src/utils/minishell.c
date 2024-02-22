/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:06 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/22 10:41:22 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_session(t_session *session)
{
	session->commands = NULL;
	session->lexer_list = NULL;
	session->pid = NULL;
	session->heredoc = false;
	session->reset_program = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	// TODO: implement
	/* parse_env(session); */
	// TODO: implement
	/* init_signals(); */
	return (1);
}

int init_session_pwd_vars(t_session *session) 
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

int	reset_session(t_session *session)
{
	// TODO: implement
	/* ft_commands_clear(&session->commands); */
	free(session->args);
	if (session->pid)
		free(session->pid);
	// TODO: implement
	/* free_arr(session->paths); */
	init_session(session);
	session->reset_program = true;
	minishell(session);
	return (1);
}


int	minishell(t_session *session)
{
	char	*tmp;

	session->args = readline(PROMPT);
	tmp = ft_strtrim(session->args, " ");
	free(session->args);
	session->args = tmp;
	if (!session->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}

	// special case?
	if (session->args[0] == '\0')
		return (reset_session(session));

	// TODO: implement
	/* add_history(session->args); */
	// TODO: implement
	/* if (!count_quotes(session->args)) */
	/*     return (ft_error(2, session)); */
	// TODO: implement
	/* if (!token_reader(session)) */
	/*     return (ft_error(1, session)); */
	// TODO: implement
	/* parser(session); */
	// TODO: implement
	/* prepare_executor(session); */

	reset_session(session);
	return (1);
}
