/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:28:25 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/16 19:33:56 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	remove_sign(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = remove_sign(n);
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

/* // temp for main */
/* void	ft_putchar_fd(char c, int fd) */
/* { */
/*     write(fd, &c, 1); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     int i; */
/*  */
/*     for (i = -10; i <= 10; i++) */
/*     { */
/*         ft_putnbr_fd(i, 1); */
/*         write(1, "\n", 1); */
/*     } */
/* } */
