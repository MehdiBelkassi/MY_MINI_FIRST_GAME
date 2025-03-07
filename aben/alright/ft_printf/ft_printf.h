/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:21:31 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/23 01:17:28 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *s);
int	ft_putpointer(void *ptr);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_hexa(int n, char type);
int	ft_putnbr_un(unsigned int n);
int	ft_printf(const char *str, ...);

#endif