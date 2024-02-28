/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:49:07 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/28 09:25:21 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char		*find_path_var(char **env)
{
	int		i;
	const char *path_prefix;
	char *path_value;

	path_prefix = "PATH=";
	if (!env) 
		return (NULL);
	while (env[i] != NULL) 
	{
		if (strncmp(env[i], path_prefix, strlen(path_prefix)) == 0) 
		{
			path_value = env[i] + strlen(path_prefix);
			return (strdup(path_value));
		}
		i++;
	}
	return (NULL);
}

static char		*ensure_trailing_slash(const char *path) 
{
	size_t path_len;

	path_len = strlen(path);
	if (path[path_len - 1] != '/') 
	{
		char *new_path = malloc(path_len + 2);
		if (new_path) 
		{
			strcpy(new_path, path);
			new_path[path_len] = '/';
			new_path[path_len + 1] = '\0';
		}
		return (new_path);
	}
	return strdup(path);
}

static int	update_paths(char **paths) 
{
	char	*updated_path;
	int		i;

	i = 0;
	while (paths[i] != NULL) 
	{
		updated_path = ensure_trailing_slash(paths[i]);
		if (!updated_path) {
			free_arr(paths);
			return (EXIT_FAILURE);
		}
		free(paths[i]);
		paths[i] = updated_path;
		i++;
	}
	return EXIT_SUCCESS;
}

int		init_session_path(t_session *session) 
{
	char *path_from_env;

	path_from_env = find_path_var(session->env);
	if (!path_from_env) 
		return (EXIT_FAILURE);
	session->paths = ft_split(path_from_env, ':');
	free(path_from_env);

	if (!session->paths || update_paths(session->paths) == EXIT_FAILURE)
	{
		free_arr(session->paths);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
