/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:24 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/26 00:37:27 by mbelkass         ###   ########.fr       */
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
	static int	c_and_e;

	if ((newmap[x][y] == 'C' || newmap[x][y] == 'E' || newmap[x][y] == 'P'
			|| newmap[x][y] == '0') && newmap[x][y] != 'V')
	{
		if (newmap[x][y] == 'C' || newmap[x][y] == 'E')
		{
			c_and_e++;
			if (c_and_e == game->collectibles + 1)
				return (1);
		}
		newmap[x][y] = 'V';
		if (floodfill_dfs(game, x - 1, y, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x + 1, y, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x, y - 1, newmap) == 1)
			return (1);
		if (floodfill_dfs(game, x, y + 1, newmap) == 1)
			return (1);
	}
	return (0);
}
