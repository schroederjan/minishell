/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:49:23 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/28 09:36:43 by jschroed         ###   ########.fr       */
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

// init

int		init_session(t_session *session);
int		init_session_path(t_session *session);
int		init_session_pwd(t_session *session);
void	init_session_signals(void);

// cleanup

int		reset_session(t_session *session);
void	reset_commands(t_commands **commands_lst);
void	reset_lexer(t_lexer **lexer_lst);

// core

int		minishell(t_session *session);

// lexer

int				parse_input(t_session *session);
t_tokens		identify_token(const char *str, int pos);
int				handle_token(char *str, int pos, t_lexer **lexer_list, t_tokens ttype);

t_lexer			*ft_lexer_new_node(char *str, int token);
void			ft_lexer_add_node_back(t_lexer **lst, t_lexer *new_node);
int				add_lexer_node(char *tval, t_tokens ttype, t_lexer **head);

// utils

char	**ft_arrdup(char **arr);
void	free_arr(char **arr);

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
