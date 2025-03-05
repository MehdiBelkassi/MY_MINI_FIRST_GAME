/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:09 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/04 22:31:16 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map, MAX_MAP_SIZE);
	if (game->moves_str)
		free(game->moves_str);
	exit(0);
	return (0);
}

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
