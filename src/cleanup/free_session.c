/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:31:57 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/12 14:37:06 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_pointer(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

void	free_array_str(char **array)
{
	int i = 0;

	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

// TODO: implement token struct
/* void	lstdelone_token(t_token *lst) */
/* { */
/*     if (!lst) */
/*         return; */
/*     free(lst->str); */
/*     free(lst->str_backup); */
/*     free(lst); */
/* } */

/* void	lstclear_token(t_token **lst) */
/* { */
/*     t_token	*tmp; */
/*  */
/*     while (*lst) */
/*     { */
/*         tmp = (*lst)->next; */
/*         token_lstdelone(*lst); */
/*         *lst = tmp; */
/*     } */
/* } */


void	free_session(t_session *session, bool clear_history)
{
	if (session && session->input)
	{
		free_pointer(session->input);
		session->input = NULL;
	}
	// TODO: implement free_cmd_list and token struct
	/* if (session && session->token) */
	/*     lstclear_token(&session->token); */
	/* if (session && session->cmd) */
	/*     free_cmd_list(&session->cmd, &free_pointer); */
	if (clear_history)
	{
		if (session && session->pwd)
			free_pointer(session->pwd);
		if (session && session->old_pwd)
			free_pointer(session->old_pwd);
		if (session && session->env)
			free_array_str(session->env);
		rl_clear_history();
	}
}



