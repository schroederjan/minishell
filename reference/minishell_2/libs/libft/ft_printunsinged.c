/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsinged.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:54:44 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/30 09:08:39 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsignedlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_putunsigned(unsigned int n)
{
	if (n >= 10)
		ft_putunsigned(n / 10);
	n = n % 10;
	ft_printchar(n + '0');
}

int	ft_printunsigned(unsigned int n)
{
	int	count;

	if (n == 0)
		count = write(1, "0", 1);
	else
	{
		count = 0;
		ft_putunsigned(n);
		count += ft_unsignedlen(n);
	}
	return (count);
}
