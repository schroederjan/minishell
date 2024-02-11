/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:54:43 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/10 20:26:32 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len);
	ft_strlcat(ret, s2, len);
	return (ret);
}

/* // temp for main */
/* size_t	ft_strlen(char const *s) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while(*s++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* size_t	ft_strlcpy(char *dest, const char *src, size_t size) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while(*src && i + 1 < size) */
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
/* size_t	ft_strlcat(char *dest, const char *src, size_t size) */
/* { */
/*     size_t	i; */
/*     size_t	ret; */
/*  */
/*     i = 0; */
/*     while(*dest && i < size) */
/*     { */
/*         dest++; */
/*         i++; */
/*     } */
/*     ret = ft_strlcpy(dest, src, size - i); */
/*     return (ret + i); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char const *s1 = "abc"; */
/*     char const *s2 = "def"; */
/*     char *joined; */
/*  */
/*     joined = ft_strjoin(s1, s2); */
/*     printf("%s\n", joined); */
/*     free(joined); */
/* } */
