/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:49:23 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/21 11:04:42 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ########
// INCLUDES
// ########

# include "minishell_structs.h"
# include "minishell_defines.h"
# include "minishell_includes.h"

// #########
// FUNCTIONS
// #########

int		init_session(t_session *session);
int		reset_session(t_session *session);
int		minishell(t_session *session);

// termination
// void	exit_shell(t_session *session, int exit_number);
// void	free_session(t_session *session, bool clear_history);
// void	free_array_str(char **array);
// void	free_pointer(void *ptr);

// GLOBAL

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

extern t_global	g_global;

#endif
