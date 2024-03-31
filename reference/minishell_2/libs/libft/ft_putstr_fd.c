/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:30:07 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/16 19:09:48 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

/* // temp for main */
/* void	ft_putchar_fd(char c, int fd) */
/* { */
/*     write(fd, &c, 1); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     char *s = "Hello."; */
/*     ft_putstr_fd(s, 1); */
/* } */
/*  */
