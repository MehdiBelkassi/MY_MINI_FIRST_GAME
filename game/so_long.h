/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:05 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/23 22:35:02 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h> // For open()
# include <mlx.h>
# include <stdlib.h> // For malloc(), free(), exit()
# include <unistd.h> // For close()

# define TILE_SIZE 32
# define MAX_MAP_SIZE 2000

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
	void	*enemy_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int		frame;
	char	*moves_str;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}			t_game;

void		free_map(char **map, int map_height);
char		**read_map(const char *file, int *map_width, int *map_height);
void		validate_map(t_game *game);
void		render_map(t_game *game);
void		update_moves_display(t_game *game);
int			game_loop(t_game *game);
int			key_hook(int keycode, t_game *game);
int			close_window(t_game *game);
void		check_valid_path(t_game *game);
void		flood_fill(char **temp_map, int x, int y, t_game *game);
int			is_surrounded_by_walls(char **map, int x, int y);
char		**process_map_lines(int fd, char **map, int *map_height,
				int *map_width);
void		check_empty_map(char **map, int *map_height, int *map_width);
void		validate_help(t_game *game, int x, int y, char c);
char		**malloc_readmap_helper(char **map, int fd);
void		handle_err(int fd, char *message);
void		process_line(char *line, char **map, int *map_height, int fd);
void 		valid_pieces(t_game *game);
#endif
