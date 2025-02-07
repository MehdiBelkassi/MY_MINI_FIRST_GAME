/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:34:36 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/23 23:34:54 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_to_hex(unsigned int nmb, char *bu, const char *hex)
{
	int				i;
	int				len;

	i = 8;
	len = 0;
	bu[i--] = '\0';
	while (nmb > 0)
	{
		bu[i--] = hex[nmb % 16];
		nmb = nmb / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_hexa(int n, char type)
{
	const char	*hexdigits;
	int			len;
	char		buffer[9];

	len = 0;
	if (type == 'x')
		hexdigits = "0123456789abcdef";
	else
		hexdigits = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	len = convert_to_hex((unsigned int)n, buffer, hexdigits);
	return (write(1, &buffer[8 - len], len));
}
