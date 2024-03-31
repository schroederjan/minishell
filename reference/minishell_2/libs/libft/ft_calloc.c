/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:15:52 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/09 19:25:09 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	if (num != 0 && SIZE_MAX / num < size)
		return (NULL);
	ret = malloc(size * num);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * num);
	return (ret);
}

/* // only temp for main */
/* void	ft_bzero(void *s, size_t n) */
/* { */
/*     unsigned char	*dest; */
/*     size_t			i; */
/*  */
/*     dest = s; */
/*     i = 0; */
/*     while(i++ < n) */
/*         *dest++ = 0; */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     int *arr; */
/*     int n = 10;  // size of the array */
/*  */
/*     // allocate and zero-initialize an array of 10 integers */
/*     arr = ft_calloc(n, sizeof(int)); */
/*     if (!arr) { */
/*         printf("Memory allocation failed\n"); */
/*         return 1; */
/*     } */
/*  */
/*     // print the array elements */
/*     for (int i = 0; i < n; i++) { */
/*         printf("%d ", arr[i]); */
/*     } */
/*  */
/*     // free the allocated memory */
/*     free(arr); */
/*  */
/*     return 0; */
/* } */
