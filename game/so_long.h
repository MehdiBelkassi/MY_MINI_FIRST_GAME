#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# define TILE_SIZE 64
# define MAX_MAP_SIZE 2000

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *wall_img;
    void    *space_img;
    void    *collectible_img;
    void    *exit_img;
    void    *player_img;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
    int     frame;
    char    *moves_str;
} t_game;

void	free_map(char **map, int map_height);
char	**read_map(const char *file, int *map_width, int *map_height);
void	validate_map(t_game *game);
void	render_map(t_game *game);
void	update_moves_display(t_game *game);
int		game_loop(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_window(t_game *game);

#endif
