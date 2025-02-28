/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:15:15 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/27 22:45:36 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map, game->map_height);
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
