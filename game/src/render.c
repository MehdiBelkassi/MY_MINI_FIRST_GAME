#include "so_long.h"

void update_moves_display(t_game *game)
{
    char temp[32];
    snprintf(temp, sizeof(temp), "Moves: %d", game->moves);
    
    if (game->moves_str)
        free(game->moves_str);
    game->moves_str = strdup(temp);
    
    // Display the move counter in white oclor
    mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, game->moves_str);
}
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
                img =game->player_img;

            if (img)
                mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
    update_moves_display(game);
}