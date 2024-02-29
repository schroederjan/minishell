/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:06 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/29 16:39:07 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	minishell(t_session *session)
{
	char	*tmp;

	session->arg = readline(PROMPT);
	tmp = ft_strtrim(session->arg, " \t\n\v\f\r");
	free(session->arg);
	session->arg = tmp;
	if (!session->arg)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}

	// special case?
	if (session->arg[0] == '\0')
	{
		printf("inside_minishell reset_session\n");
		return 1;
		/* return (reset_session(session)); */
	}
	add_history(session->arg);

	// TODO: implement
	/* if (!count_quotes(session->arg)) */
	/*     return (ft_error(2, session)); */

	if (!parse_input(session))
		return (EXIT_FAILURE);

	// TODO: implement
	/* parser(session); */
	// TODO: implement
	/* prepare_executor(session); */

	printf("end reset_session\n");
	reset_session(session);
	return (1);
}

