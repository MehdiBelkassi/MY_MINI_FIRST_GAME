/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:27 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/09 23:58:33 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
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
		{
			ft_printf("\033[2J\033[H\033[32mYou won!\033[0m\n");
			return (close_window(game));
		}
		else
		{
			ft_printf("\033[2J\033[H\033[31mCollect All Diamonds First !\033[0m");
			return (1);
		}
	}
	return (0);
}

static void	process_movement(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'E')
		{
			if (handle_exit(game, new_x, new_y))
				return ;
			if (game->collectibles > 0)
				return ;
		}
		move_player(game, new_x, new_y);
		game->moves++;
		ft_printf("\033[2J\033[H\033[33mthe moves : %d\033[0m ", game->moves);
		mlx_clear_window(game->mlx, game->win);
		render_map(game);
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
