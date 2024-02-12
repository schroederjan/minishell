/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:48:03 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/12 14:44:27 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_exit_code;

static void minishell(t_session *session)
{
	while (1)
	{
		/* handle_interactive_session_signal(); */
		session->input = readline(PROMPT);
		if (session->input)
		{
			ft_printf("exit\n");
			return (exit_shell(session, 0));
		}
		/* handle_non_interactive_session_signal(); */
		add_history(session->input);
		/* if (lexer(session)) */
		/* { */
		/*     lstadd_back_token(&session->token, lstnew_token(NULL, END)); */
		/*     strip_space_token(&session->token); */
		/*     if (check_syntax(&session->token)) */
		/*         g_exit_code = 2; */
		/*     else */
		/*     { */
		/*         parser(session); */
		/*         g_exit_code = executor(session); */
		/*     } */
		/* } */
		/* free_session(session, false); */
	}
}

int main(int argc, char **argv, char **env)
{
	t_session session;
	(void)argv;
	//TODO remove when implemented env
	(void)env;

	// TODO: why use memset?
	ft_memset(&session, 0, sizeof(t_session));
	if (argc != 1)
		return (ft_putendl_fd("No arguments allowed!", 2), 1);
	// TODO: implement init_session
	/* if (!init_session(&session, env)) */
	/*     exit_shell(&session, EXIT_FAILURE)) */
	minishell(&session);
	exit_shell(&session, g_exit_code);
	return (0);
}
