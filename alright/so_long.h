/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:05 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/08 08:11:12 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32
# define MAX_MAP_SIZE 2000

typedef struct s_game
{
	void	*mlx;
	int		c_and_e;
	void	*win;
	void	*wall_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
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

void		check_extension(char *file);
void		free_map(char **map, int map_height);
char		**read_map(const char *file, int *map_width, int *map_height);
void		validate_map(t_game *game);
void		render_map(t_game *game);
int			game_loop(t_game *game);
int			key_hook(int keycode, t_game *game);
int			close_window(t_game *game);
void		validate_help(t_game *game, int x, int y, char c);
char		**malloc_readmap_helper(char **map, int fd, int map_height);
void		handle_err(int fd, char *message);
void		process_line(char *line, char **map, int *map_height, int fd);
void		valid_pieces(t_game *game);
char		**copymap(t_game *game);
int			floodfill_dfs(t_game *game, int x, int y, char **newmap);
size_t		ft_strcspn(const char *s, const char *reject);

#endif
