/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:45:30 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/08 20:55:35 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (1)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		if (!*s)
			break ;
		s++;
	}
	return (ret);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     const char *s = "ababa"; */
/*     int c = 'b'; */
/*  */
/*     printf("%s\n", ft_strrchr(s, c)); */
/* } */
