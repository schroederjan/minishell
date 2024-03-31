/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:50:38 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/09 08:50:40 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

/* // temp func for main only */
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
/* size_t	ft_strlcpy(char *dest, const char *src, size_t size) */
/* { */
/*     size_t	i; */
/*      */
/*     i = 0; */
/*     while (*src && i < size - 1) */
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
/*     printf("%s\n", ft_strdup("abc")); */
/* } */
