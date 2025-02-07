/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:21 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:22 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_game *game) {
    for (int y = 0; y < game->map_height; y++) {
        for (int x = 0; x < game->map_width; x++) {
            void *img = NULL;

            if (game->map[y][x] == '1')
                img = game->wall_img;
            else if (game->map[y][x] == '0')
                img = game->space_img;
            else if (game->map[y][x] == 'C')
                img = game->collectible_img;
            else if (game->map[y][x] == 'E')
                img = game->exit_img;
            else if (game->map[y][x] == 'P')
                img = game->player_img;

            if (img)
                mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}