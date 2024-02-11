/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:01:02 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/10 09:33:50 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1);
		if (sub)
			*sub = 0;
		return (sub);
	}
	if (s_len < len + start)
		len = s_len - start;
	sub = malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// edge cases:
// 1. s = 0, 
// 2. start >= s_len, the index beyond s, create empty string malloc(1)
// 3. s_len - start < len

/* // temp for main only */
/* size_t	ft_strlen(char const *s) // char const are adapted to substring */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*s++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* size_t	ft_strlcpy(char *dest, char const *src, size_t size) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*src && i + 1 < size) */
/*     { */
/*         *dest++ = *src++; */
/*         i++; */
/*     } */
/*     if (i < size) */
/*         *dest = 0; */
/*     while (*src++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char const		*s = "hello and world"; */
/*     unsigned int	start; */
/*     size_t			len = 3; */
/*     char			*sub; */
/*  */
/*     for (start = 0; start < 20; start++) */
/*     { */
/*         sub = ft_substr(s, start, len); */
/*         if (sub != NULL) */
/*         { */
/*             printf("start: %d sub: %s\n", start, sub); */
/*             free(sub); */
/*         } */
/*         else */
/*             printf("Substring operation failed.\n"); */
/*     } */
/*     return (0); */
/* } */
