/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:36:52 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/22 09:42:15 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_arr(char **arr) 
{
	size_t i = 0;
	if (arr != NULL) {
		while (arr[i] != NULL) {
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

char **ft_arrdup(char **arr) 
{
	size_t i;
	char **arrdup;

	i = 0;
	while (arr[i] != NULL)
		i++;
	arrdup = ft_calloc(i + 1, sizeof(char *));
	if (!arrdup)
		return (NULL);
	i = 0;
	while (arr[i] != NULL) {
		arrdup[i] = ft_strdup(arr[i]);
		if (arrdup[i] == NULL) {
			free_arr(arrdup);
			return (NULL);
		}
		i++;
	}
	return arrdup;
}
