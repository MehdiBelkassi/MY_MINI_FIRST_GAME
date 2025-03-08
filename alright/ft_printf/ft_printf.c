/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:03 by mbelkass          #+#    #+#             */
/*   Updated: 2024/12/03 21:00:23 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(type));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		check;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%' && (*str + 1) != '\0' && str++) 
		{
			if (!*str)
				return (len);
			check = ft_convert(*(str), args);
			if (check == -1)
				return (-1);
			len = len + check;
		}
		else if (write(1, str, 1) == -1)
			return (-1);
		else
			len++;
		str++;
	}
	va_end(args);
	return (len);
}
