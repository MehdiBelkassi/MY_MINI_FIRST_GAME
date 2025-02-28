/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:00 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/28 05:14:38 by mbelkass         ###   ########.fr       */
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

char	**copymap(t_game *game)
{
	char	**newmap;
	int		i;
	int		lenj;

	i = 0;
	lenj = ft_strlen(game->map[0]);
	newmap = malloc(sizeof(char *) * (game->map_height + 1));
	if (!newmap)
		return (NULL);
	while (i < game->map_height)
	{
		newmap[i] = malloc(sizeof(char) * (lenj + 1));
		if (!newmap[i])
			return (NULL);
		ft_strlcpy(newmap[i], game->map[i], lenj + 1);
		i++;
	}
	newmap[i] = NULL;
	return (newmap);
}

int	floodfill_dfs(t_game *game, int x, int y, char **newmap)
{
	if ((newmap[y][x] == 'C' || newmap[y][x] == 'E' || newmap[y][x] == 'P'
			|| newmap[y][x] == '0') && newmap[y][x] != 'V')
	{
		if (newmap[y][x] == 'C' || newmap[y][x] == 'E')
		{
			game->c_and_e++;
			if (game->c_and_e == game->collectibles + 1)
				return (1);
		}
		if (newmap[y][x] == 'E')
		{
			newmap[y][x] = 'V';
			return (0);
		}
		newmap[y][x] = 'V';
		if (floodfill_dfs(game, x, y + 1, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x, y - 1, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x + 1, y, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x - 1, y, newmap) == 1)
			return (1);
	}
	return (0);
}
