/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:51 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/08 05:48:28 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_fd(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		handle_err(*fd, "Error opening file\n");
}

char	**read_map(const char *file, int *map_width, int *map_height)
{
	char	*line;
	int		fd;
	char	**map;

	handle_fd(&fd, (char *)file);
	*map_height = 1;
	while ((line = get_next_line(fd)) && *map_height < MAX_MAP_SIZE)
	{
		(*map_height)++;
		free(line);
	}
	close(fd);
	handle_fd(&fd, (char *)file);
	map = malloc(sizeof(char *) * (*map_height + 1));
	if (!map)
		handle_err(fd, "memory allocation error");
	*map_height = 0;
	while ((line = get_next_line(fd)) && *map_height < MAX_MAP_SIZE)
		process_line(line, map, map_height, fd);
	map[*map_height] = NULL;
	if (*map_height == 0)
		handle_err(fd, "Error: Empty map file\n");
	close(fd);
	*map_width = ft_strlen(map[0]);
	return (map);
}

static void	print_error_exit(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	free_map(game->map, game->map_height);
	exit(1);
}

void	validate_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	game->exit_count = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	y = -1;
	while (++y < game->map_height)
	{
		if ((int)ft_strlen(game->map[y]) != game->map_width)
			print_error_exit("Map is not rectangular.", game);
		x = -1;
		while (++x < game->map_width)
		{
			c = game->map[y][x];
			validate_help(game, x, y, c);
		}
		game->collectibles = game->collectible_count;
	}
}

void	validate_help(t_game *game, int x, int y, char c)
{
	if ((y == 0 || y == game->map_height - 1 || x == 0 || x == game->map_width
			- 1) && c != '1')
		print_error_exit("Map is not surrounded by walls.", game);
	if (c == 'E')
		game->exit_count++;
	else if (c == 'P')
	{
		game->player_count++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == 'C')
		game->collectible_count++;
	else if (c != '1' && c != '0')
	{
		ft_printf("Error\nInvalid character '%c' in map.\n", c);
		free_map(game->map, game->map_height);
		exit(1);
	}
}
