/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:09:59 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/09 19:20:04 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

/* #include <stdio.h> */
/* #include <string.h> */
/* #include <stdlib.h> */
/*  */
/* int	main(void) */
/* { */
/*     char	*s = malloc(sizeof(char) * 3); */
/*     size_t	n = 2; */
/*  */
/*     strcpy(s, "hi"); // cp string literal to pinter */
/*     ft_bzero(s, n); // set to zero */
/*     for (size_t i = 0; i < n; i++) { */
/*         printf("%d ", s[i]); */
/*     } */
/*  */
/*     free(s); // Don't forget to free the memory */
/*  */
/*     return 0; */
/* } */
