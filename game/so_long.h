/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:05 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/21 22:34:41 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>     // For open()
# include <stdlib.h>    // For malloc(), free(), exit()
# include <unistd.h>    // For close()

# define TILE_SIZE 32
# define MAX_MAP_SIZE 2000

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *wall_img;
    void    *space_img;
    void    *collectible_img;
    void    *exit_img;
    void    *player_img;
    void    *enemy_img;
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

// Function prototypes

void    free_map(char **map, int map_height);
char    **read_map(const char *file, int *map_width, int *map_height);
void    validate_map(t_game *game);
void    render_map(t_game *game);
void    update_moves_display(t_game *game);
int     game_loop(t_game *game);
int     key_hook(int keycode, t_game *game);
int     close_window(t_game *game);
void    check_valid_path(t_game *game);
void    flood_fill(char **temp_map, int x, int y, t_game *game);
int     is_surrounded_by_walls(char **map, int x, int y);




#endif