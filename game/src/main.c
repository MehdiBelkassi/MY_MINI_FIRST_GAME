/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:14 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/16 23:03:07 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//adding the enemy and done
int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        ft_printf("Usage: ./game map.ber\n");
        return (1);
    }

    t_game  game;
    game.moves = 0;
    game.frame = 0;
    game.moves_str = NULL;
    game.map = read_map(argv[1], &game.map_width, &game.map_height);

    validate_map(&game);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "So Long Game");

    int width, height;
    game.wall_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &width, &height);
    game.space_img = mlx_xpm_file_to_image(game.mlx, "space.xpm", &width, &height);
    game.collectible_img = mlx_xpm_file_to_image(game.mlx, "collectible.xpm", &width, &height);
    game.exit_img = mlx_xpm_file_to_image(game.mlx, "exit.xpm", &width, &height);
    game.player_img = mlx_xpm_file_to_image(game.mlx, "player.xpm", &width, &height);
    game.enemy_img = mlx_xpm_file_to_image(game.mlx, "enemy.xpm", &width, &height);
    

    if (!game.wall_img || !game.space_img || !game.collectible_img || 
        !game.exit_img || !game.player_img || !game.enemy_img)
    {
        ft_printf("Error\nFailed to load one or more XPM files.\n");
        free_map(game.map, game.map_height);
        exit(1);
    }

    mlx_hook(game.win, 17, 0, close_window, &game);  // Handle window close button
    mlx_key_hook(game.win, key_hook, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    
    render_map(&game);
    mlx_loop(game.mlx);

    return (0);
}
