/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:49:23 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/21 10:58:37 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

# include "minishell_includes.h"

// Lists:
// - lexer_list = t_lexer
// - redirections_list = t_lexer

// TOKENS

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

// LEXER

typedef struct s_lexer
{
	char			*word;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

// PARSER

typedef struct s_parser
{
	t_lexer			*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	struct s_tools	*tools;
}	t_parser;

// SESSION

typedef struct s_session
{
	char				*args;
	char				**paths;
	char				**env;
	struct s_commands	*commands;
	t_lexer				*lexer_list;
	char				*pwd;
	char				*old_pwd;
	int					pipes;
	int					*pid;
	bool				heredoc;
	bool				reset_program;
}	t_session;

// COMMANDS

typedef struct s_commands
{
	char				**str; // eg. echo a
						// builtin_arr
	int					(*builtin)(t_session *, struct s_commands *); // eg. echo
	int					num_redirections;
	char				*hd_file_name;
	t_lexer				*redirections; // eg. >file
	struct s_commands	*next;
	struct s_commands	*prev;
}	t_commands;

#endif

