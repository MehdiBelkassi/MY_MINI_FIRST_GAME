/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:35:25 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/22 23:59:05 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	char			*hexdigits;
	char			buffer[19];
	int				len;
	int				i;

	hexdigits = "0123456789abcdef";
	address = (unsigned long)ptr;
	i = 18;
	len = 0;
	buffer[i--] = '\0';
	if (!ptr)
		return (write(1, "0x0", 3));
	while (address > 0)
	{
		buffer[i--] = hexdigits[address % 16];
		address = address / 16;
		len++;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	return (write(1, &buffer[i], len + 2));
}
