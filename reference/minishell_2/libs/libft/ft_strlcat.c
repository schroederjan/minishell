/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:30:13 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/07 20:26:54 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	ret = ft_strlcpy(dest, src, size - i);
	return (ret + i);
}

/* // TEMPORARY IMPLEMENTATION FOR MAIN */
/* size_t	ft_strlcpy(char *dst, const char *src, size_t size) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*src && i + 1 < size) */
/*     { */
/*         *dst++ = *src++; */
/*         i++; */
/*     } */
/*     if (i < size) */
/*         *dst = 0; */
/*     while (*src++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* #include <stdio.h> */
/* #include <string.h> */
/* int	main(void) */
/* { */
/*     char	original_dest[] = "abc"; */
/*     char	dest[6]; */
/*     char	*src = "123"; */
/*     size_t result; */
/*     size_t	size; */
/*  */
/*     for (size = 1; size <= 7; size++) */
/*     { */
/*         strncpy(dest, original_dest, sizeof(dest)); */
/*         result = ft_strlcat(dest, src, size); */
/*         printf("return: %zu, dest: %s, size: %zu\n", result, dest, size); */
/*     } */
/* } */
