/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:03:32 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/30 09:08:24 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(uintptr_t num)
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

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
		ft_putptr(num / 16);
	num = num % 16;
	if (num <= 9)
		ft_printchar(num + '0');
	else
		ft_printchar(num - 10 + 'a');
}

int	ft_printptr(uintptr_t ptr)
{
	int	count;

	if (ptr == 0)
		count = write(1, "(nil)", 5);
	else
	{
		count = 0;
		count += write(1, "0x", 2);
		ft_putptr(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}
