/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:53:47 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/30 09:08:12 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_putint(long long n)
{
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putint(n / 10);
	ft_printchar(n % 10 + '0');
}

int	ft_printint(int n)
{
	int	count;

	if (n == 0)
		count = write(1, "0", 1);
	else
	{
		count = 0;
		ft_putint((long long)n);
		count += ft_intlen(n);
	}
	return (count);
}
