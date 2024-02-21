/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:48:03 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/21 11:05:25 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global g_global;

int	main(int argc, char **argv, char **env)
{
	t_session	session;

	// TODO: implement
	(void)env;

	if (argc != 1 || argv[1])
		return (ft_putendl_fd("No arguments allowed!", 2), 1);
	// TODO: implement
	/* session.env = ft_arrdup(env); */
	// TODO: implement
	/* find_pwd(&session); */
	init_session(&session);
	minishell(&session);
	return (0);
}
