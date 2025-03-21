/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:42 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/10 02:10:17 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error(t_game *game)
{
	ft_putstr_fd("Invalid map for flood fill\n", 2);
	free_map(game->map, game->map_height);
	exit(1);
}

static void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->space_img = mlx_xpm_file_to_image(game->mlx, "textures/space.xpm",
			&width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	if (!game->wall_img || !game->space_img || !game->collectible_img
		|| !game->exit_img || !game->player_img)
	{
		ft_printf("Error\nFailed to load one or more XPM files.\n");
		free_map(game->map, game->map_height);
		exit(1);
	}
}

static void	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "So Long Game");
	load_images(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	render_map(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**newmap;

	if (argc != 2)
	{
		ft_printf("Usage: ./game map.ber\n");
		return (1);
	}
	check_extension(argv[1]);
	game.c_and_e = 0;
	game.map = read_map(argv[1], &game.map_width, &game.map_height);
	validate_map(&game);
	valid_pieces(&game);
	newmap = copymap(&game);
	if (floodfill_dfs(&game, game.player_x, game.player_y, newmap) == 0)
	{
		free_map(newmap, game.map_height);
		ft_error(&game);
	}
	free_map(newmap, game.map_height);
	game.mlx = mlx_init();
	start_game(&game);
	free_map(game.map, game.map_height);
	return (0);
}
