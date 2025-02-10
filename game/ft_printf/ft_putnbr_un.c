/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 03:40:12 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/22 09:29:55 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int		len;
	int		ret;

	len = 0;
	if (n > 9)
	{
		ret = ft_putnbr_un(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = write(1, &"0123456789"[n % 10], 1);
	if (ret == -1)
		return (-1);
	return (len + ret);
}
