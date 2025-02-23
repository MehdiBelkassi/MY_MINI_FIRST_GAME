/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:24 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/23 17:34:52 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int map_height)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < map_height)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}
