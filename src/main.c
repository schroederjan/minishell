/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:48:03 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/28 09:22:42 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global g_global;

int	main(int argc, char **argv, char **env)
{
	t_session	session;

	if (argc != 1 || argv[1])
		return (ft_putendl_fd("No arguments allowed!", 2), 1);
	session.env = ft_arrdup(env);
	init_session_pwd(&session);
	init_session(&session);
	minishell(&session);
	return (0);
}
