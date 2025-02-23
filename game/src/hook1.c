/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:37:18 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/23 17:33:12 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	static int	frame_counter;

	frame_counter = 0;
	frame_counter++;
	if (frame_counter % 30 == 0)
	{
		game->frame = !game->frame;
		mlx_clear_window(game->mlx, game->win);
		render_map(game);
		update_moves_display(game);
	}
	return (0);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map[new_y][new_x] == 'W')
	{
		ft_printf("aie..");
		close_window(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}

static int	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
			ft_printf("You won!\n");
		else
			ft_printf("You won... but at what cost?! :(");
		return (close_window(game));
	}
	return (0);
}

static void	process_movement(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (handle_exit(game, new_x, new_y))
			return ;
		move_player(game, new_x, new_y);
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		render_map(game);
		update_moves_display(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == 53)
		return (close_window(game));
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 13 || keycode == 126)
		new_y--;
	else if (keycode == 1 || keycode == 125)
		new_y++;
	else if (keycode == 0 || keycode == 123)
		new_x--;
	else if (keycode == 2 || keycode == 124)
		new_x++;
	else
		return (0);
	if (new_x >= 0 && new_x < game->map_width && new_y >= 0
		&& new_y < game->map_height)
		process_movement(game, new_x, new_y);
	return (0);
}
