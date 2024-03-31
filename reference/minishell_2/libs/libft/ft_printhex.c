/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:40:17 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/30 09:08:03 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char format)
{
	if (num >= 16)
		ft_puthex(num / 16, format);
	num = num % 16;
	if (num <= 9)
		ft_printchar(num + '0');
	else
	{
		if (format == 'x')
			ft_printchar(num - 10 + 'a');
		if (format == 'X')
			ft_printchar(num - 10 + 'A');
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	int	count;

	if (num == 0)
		count = write(1, "0", 1);
	else
	{
		count = 0;
		ft_puthex(num, format);
		count += ft_hexlen(num);
	}
	return (count);
}
