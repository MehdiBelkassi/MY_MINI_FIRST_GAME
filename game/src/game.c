#include "so_long.h"

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    free_map(game->map, game->map_height);
    if (game->moves_str)
        free(game->moves_str);
    exit(0);
    return (0);
}