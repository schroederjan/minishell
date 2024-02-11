/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:37:37 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/22 18:35:00 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
		number = number * 10 + sign * (*str++ - '0');
	return ((int)number);
}

/* // temp for main */
/* #include <stdio.h> */
/*  */
/* int	ft_isdigit(int c) */
/* { */
/*     return (c >= '0' && c <= '9'); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     printf("%d\n", ft_atoi("42")); */
/* }	 */
