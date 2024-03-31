/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:40:50 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/07 14:59:14 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

// // example for not overlapping mems
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     unsigned char dest[] = "12345"; */
/*     const unsigned char *src = (const unsigned char *)"abcde"; */
/*     size_t n = 1; */
/*  */
/*     ft_memmove(dest, src, n); */
/*     printf("%s\n", (unsigned char *)ft_memmove(dest, src, n)); */
/* } */

// // example for overlapping mems
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     unsigned char buffer[] = "hello world"; */
/*     size_t n = 2; // Number of characters to move */
/*                   // */
/*     printf("Before memmove: %s\n", buffer); */
/*  */
/*     // Move the first 6 chars 2 positions to the right within the buffer */
/*     ft_memmove(buffer + 2, buffer, n); */
/*     printf("After memmove: %s\n", buffer); */
/* } */

/* Before memmove: hello world */
/* After memmove: heheo world // copy 2 shifted by two, in same buffer */
