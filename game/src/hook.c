#include "so_long.h"

int game_loop(t_game *game)
{
    static int frame_counter = 0;
    
    frame_counter++;
    if (frame_counter % 30 == 0) {
        game->frame = !game->frame;
        mlx_clear_window(game->mlx, game->win);
        render_map(game);
    }
    
    return (0);
}

int key_hook(int keycode, t_game *game) {
    if (keycode == 53) // ESC key
        return close_window(game);

    int new_x = game->player_x;
    int new_y = game->player_y;

    if (keycode == 13) // W
        new_y--;
    else if (keycode == 1) // S
        new_y++;
    else if (keycode == 0) // A
        new_x--;
    else if (keycode == 2) // D
        new_x++;
    else
        return (0);

    if (new_x >= 0 && new_x < game->map_width && new_y >= 0 && new_y < game->map_height) {
        if (game->map[new_y][new_x] != '1') {
            // Handle exit condition
            if (game->map[new_y][new_x] == 'E') {
                if (game->collectibles == 0) {
                    printf("You win!\n");
                    return close_window(game);
                }
                return (0);
            }
            
            // Handle collectible
            if (game->map[new_y][new_x] == 'C')
                game->collectibles--;

            game->map[game->player_y][game->player_x] = '0';
            game->map[new_y][new_x] = 'P';
            game->player_x = new_x;
            game->player_y = new_y;
            
            game->moves++;
        }
    }

    mlx_clear_window(game->mlx, game->win);
    render_map(game);
    return (0);
}
