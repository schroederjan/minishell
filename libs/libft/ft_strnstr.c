/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:02:43 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/08 21:20:47 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	i = 0;
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (*little == 0)
		return ((char *)big);
	while (i + little_len <= len && i + little_len <= big_len)
	{
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     const char *big = "hi this is a test"; */
/*     const char *little = "is"; */
/*     size_t len = ft_strlen(big); */
/*  */
/*     printf("%s\n", ft_strnstr(big, little, len)); */
/* } */
/*  */
/* // temp func for this main */
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
/* // temp func for this main */
/* int	ft_strncmp(const char *s1, const char *s2, size_t n) */
/* { */
/*     while (n--) */
/*     { */
/*         if (*s1 != *s2 || !*s1 || !*s2) */
/*             return (*s1 - *s2); */
/*         s1++; */
/*         s2++; */
/*     } */
/*     return (0); */
/* } */
