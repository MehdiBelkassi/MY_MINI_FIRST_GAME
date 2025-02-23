/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:05 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/23 10:00:10 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		ret;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		ret = write(1, "-", 1);
		if (ret == -1)
			return (-1);
		len += ret;
		n = -n;
	}
	if (n > 9)
	{
		ret = ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = write(1, &"0123456789"[n % 10], 1);
	if (ret == -1)
		return (-1);
	return (len + ret);
}
