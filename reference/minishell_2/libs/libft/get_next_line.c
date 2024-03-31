/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:45:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/12/11 20:53:45 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO: check this get_next line implementation

/* char	*ft_read_to_stash(int fd, char *stash) */
/* { */
/*     char	*buff; */
/*     int		num_bytes_read; */
/*  */
/*     buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)); */
/*     if (!buff) */
/*         return (NULL); */
/*     num_bytes_read = 1; */
/*     while (!ft_strchr(stash, '\n') && num_bytes_read != 0) */
/*     { */
/*         num_bytes_read = read(fd, buff, BUFFER_SIZE); */
/*         if (num_bytes_read == -1) */
/*         { */
/*             free(buff); */
/*             free(stash); */
/*             return (NULL); */
/*         } */
/*         buff[num_bytes_read] = '\0'; */
/*         stash = ft_strjoin(stash, buff); */
/*     } */
/*     free(buff); */
/*     return (stash); */
/* } */
/*  */
/* char	*get_next_line(int fd) */
/* { */
/*     char		*line; */
/*     static char	*stash; */
/*  */
/*     if (fd < 0 || BUFFER_SIZE <= 0) */
/*         return (NULL); */
/*     stash = ft_read_to_stash(fd, stash); */
/*     if (!stash) */
/*         return (NULL); */
/*     line = ft_get_line(stash); */
/*     stash = ft_update_stash(stash); */
/*     return (line); */
/* } */

static void	ft_free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*get_line(char **backup, char **line)
{
	char	*next_backup;
	int		i;

	i = 0;
	next_backup = NULL;
	while (*(*backup + i) != '\n' && *(*backup + i) != '\0')
		i++;
	if (*(*backup + i) == '\n')
	{
		i++;
		*line = ft_substr(*backup, 0, i);
		next_backup = ft_strdup(*backup + i);
	}
	else
		*line = ft_strdup(*backup);
	ft_free_ptr(backup);
	return (next_backup);
}

static int	read_line(int fd, char **buffer, char **backup, char **line)
{
	int		bytes_read;
	char	*temporary;

	bytes_read = 1;
	while (!ft_strchr(*backup, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temporary = *backup;
		*backup = ft_strjoin(temporary, *buffer);
		free(temporary);
	}
	ft_free_ptr(buffer);
	*backup = get_line(backup, line);
	if (!(**line))
		ft_free_ptr(line);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer_backup = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	if (!read_line(fd, &buffer, &buffer_backup, &line) && !line)
		return (NULL);
	return (line);
}
