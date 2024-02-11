/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:08:30 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/12 18:45:52 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	is_signed(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static unsigned int	remove_sign(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*alpha;

	sign = is_signed(n);
	len = nbr_len(n);
	nbr = remove_sign(n);
	alpha = malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (NULL);
	alpha[len--] = 0;
	while (len >= 0)
	{
		alpha[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (sign == 1)
		alpha[0] = '-';
	return (alpha);
}

// temp for main
//
/* #include <stdio.h> */
/*  */
/* int	main(void) */
/* { */
/*     int		n; */
/*     char	*a; */
/*  */
/*     n = -2147483648; */
/*     a = ft_itoa(n); */
/*     printf("%s\n", a); */
/*     free(a); */
/* } */
