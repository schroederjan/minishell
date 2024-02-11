/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:35:49 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/15 19:54:33 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

/* // temp for main only */
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
/* char	my_func(unsigned int i, char c) */
/* { */
/*     printf("%d %c\n", i, c); */
/*     if (c >= 'a' && c <= 'z') */
/*         return (c - 32); */
/*     return (c); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     char	str[10] = "hello."; */
/*     char	*result; */
/*  */
/*     printf("%s\n", str); */
/*     result = ft_strmapi(str, my_func); */
/*     printf("%s\n", result); */
/*     free(result); */
/* } */
