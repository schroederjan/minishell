/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:56:08 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/16 18:07:39 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* // temp for main */
/* #include <stdio.h> */
/*  */
/* void	change_char(unsigned int i, char *s) */
/* { */
/*     if (s && *s) */
/*     { */
/*         *s += i % 26; // kept i inside alphabet */
/*     } */
/* } */
/*  */
/*  */
/* int	main(void) */
/* { */
/*     char s[] = "aaa"; */
/*  */
/*     printf("%s\n", s); */
/*     ft_striteri(s, change_char); */
/*     printf("%s\n", s); */
/* } */
