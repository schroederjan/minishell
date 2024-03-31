/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:55:20 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/11 18:20:23 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) && is_in_set(*(s1 + start), set))
		start++;
	while (end > start && is_in_set(*(s1 + end - 1), set))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	str = ret;
	while (start < end)
		*str++ = *(s1 + start++);
	*str = 0;
	return (ret);
}

/* // temp only */
/* size_t	ft_strlen(const char *s) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*s++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char const	*s1 = "abc"; */
/*     char const	*set = "ac"; */
/*     char		*trimmed; */
/*  */
/*     trimmed = ft_strtrim(s1, set); */
/*     printf("%s\n", trimmed); */
/*     free(trimmed); */
/* } */
