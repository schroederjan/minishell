/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:08:15 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/07 13:49:28 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	if (!d && !src)
		return (NULL);
	while (n--)
		*d++ = *((unsigned char *)src++);
	return (dest);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char dest[5] = "12345"; */
/*     const char *src = "abcde"; */
/*     size_t	n = 10; */
/*  */
/*     printf("%s\n", (unsigned char *)ft_memcpy(dest, src, n)); */
/* } */
