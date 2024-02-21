/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:06 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/21 10:50:30 by jschroed         ###   ########.fr       */
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
