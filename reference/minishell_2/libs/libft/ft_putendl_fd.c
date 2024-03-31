/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:16:05 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/16 19:16:34 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* // temp for main */
/* #include <unistd.h> */
/*  */
/* void	ft_putchar_fd(char c, int fd) */
/* { */
/*     write(fd, &c, 1); */
/* } */
/*  */
/* void	ft_putstr_fd(char *s, int fd) */
/* { */
/*     while (*s) */
/*         ft_putchar_fd(*s++, fd); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     char	*s = "Hello."; */
/*     ft_putendl_fd(s, 1); */
/* } */
