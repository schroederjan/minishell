/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:06 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/26 08:47:56 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	if (!token_reader(session))
		return (ft_error(1, session));
	// TODO: implement
	/* parser(session); */
	// TODO: implement
	/* prepare_executor(session); */

	reset_session(session);
	return (1);
}
