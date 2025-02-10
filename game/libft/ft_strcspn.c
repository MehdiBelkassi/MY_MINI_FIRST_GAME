/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:11 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/08 20:10:58 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i]) 
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j]) 
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
