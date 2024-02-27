/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:49:23 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/27 09:13:34 by jschroed         ###   ########.fr       */
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

// core

int		init_session(t_session *session);
int		init_session_pwd_vars(t_session *session);
int		reset_session(t_session *session);
int		minishell(t_session *session);

// lexer

t_tokens		identify_token(const char *str, int pos);
int				is_whitespace(char c);
int				skip_whitespace(char *str, int i);

int				parse_words(int start_pos, char *str, t_lexer **lexer_list);
int				parse_input(t_session *session);

int				handle_token(char *str, int pos, t_lexer **lexer_list, t_tokens ttype);

t_lexer			*ft_lexer_new_node(char *str, int token);
void			ft_lexer_add_node_back(t_lexer **lst, t_lexer *new_node);
int				add_lexer_node(char *tval, t_tokens ttype, t_lexer **head);

// utils

void	free_arr(char **arr);
char	**ft_arrdup(char **arr);
void	reset_commands(t_commands **commands_lst);
void	reset_lexer(t_lexer **lexer_lst);

// env

// signal
void	init_signals(void);

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
